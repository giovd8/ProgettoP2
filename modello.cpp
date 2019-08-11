#include "modello.h"
#include "primo.h"
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <iostream>
using namespace std;
using std::string;

//costruttore e distruttore modello
modello::modello(string s, bool b):
    piatti(new container<piattoBase*>),
    xmlFile(s),
    salvataggioEffetuato(b)
{}

modello::~modello() {
    delete piatti;
}

bool modello::getSalvataggioEffetuato() const{
    return salvataggioEffetuato;
}

void modello::setSalvataggioEffetuato(bool b) {
    salvataggioEffetuato=b;
}


void modello::nuovoPercorso(string p)
{
    xmlFile = p;
    delete piatti;
    //salvataggioEffetuato=false;
    piatti=new container<piattoBase*>();
}

//Importo dati da file XML
void modello::caricamentoDati() const {
    //converto file string in QFile
    QFile elementiMenu(QString::fromStdString(xmlFile));
    //warning se non carico nessun file xml
    if(!elementiMenu.open(QIODevice::ReadOnly)) {
        qWarning() << "Impossibile caricare i piatti del menu!" << elementiMenu.errorString();
        return ;
    }
    //inizio lettura file
    QXmlStreamReader xmlReader(&elementiMenu);
        if(xmlReader.readNextStartElement()){
            if(xmlReader.name() == "root"){
                while(xmlReader.readNextStartElement()){
                    const QXmlStreamAttributes attributi = xmlReader.attributes();
                    //prendo attributi piatto base
                    string nome=attributi.hasAttribute("nome") ? attributi.value("nome").toString().toStdString() : "";
                    bool vegano=attributi.hasAttribute("vegano") ? attributi.value("vegano").toString()=="true"? true : false : false;
                    bool glutenFree=attributi.hasAttribute("glutenFree") ? attributi.value("glutenFree").toString()=="true"? true : false : false;
                    double prezzoBase=attributi.hasAttribute("prezzoBase") ? attributi.value("prezzoBase").toDouble() : 0;
                    string urlImmagine=attributi.hasAttribute("urlImmagine") ? attributi.value("urlImmagine").toString().toStdString() : "";
                    piattoBase* insertElemento=nullptr;
                    //prendo attributi primo
                    if(xmlReader.name()=="primo"){
                        bool soia=attributi.hasAttribute("soia") ? attributi.value("soia").toString()=="true"? true : false : false;
                        string tipoPatsa=attributi.hasAttribute("tipoPasta") ? attributi.value("tipoPasta").toString().toStdString() : "";
                        string condimento=attributi.hasAttribute("condimento") ? attributi.value("condimento").toString().toStdString() : "";
                        string ingrediente1=attributi.hasAttribute("ingrediente1") ? attributi.value("ingrediente1").toString().toStdString() : "";
                        string ingrediente2=attributi.hasAttribute("ingrediente2") ? attributi.value("ingrediente2").toString().toStdString() : "";
                        string ingrediente3=attributi.hasAttribute("ingrediente3") ? attributi.value("ingrediente3").toString().toStdString() : "";
                        insertElemento=new primo(nome,vegano,glutenFree,prezzoBase,urlImmagine,soia,tipoPatsa,condimento,ingrediente1,ingrediente2,ingrediente3);
                    }
                    //prendo attributi secondo
                    if(xmlReader.name()=="secondo"){\
                        string tipoCarnePesce=attributi.hasAttribute("tipoCarnePesce") ? attributi.value("tipoCarnePesce").toString().toStdString() : "";
                        string tipoPiatto=attributi.hasAttribute("tipoPiatto") ? attributi.value("tipoPiatto").toString().toStdString() : "";
                        insertElemento=new secondo(nome,vegano,glutenFree,prezzoBase,urlImmagine,tipoCarnePesce,tipoPiatto);
                    }
                    //prendo attributi contorno
                    if(xmlReader.name()=="contorno"){
                        string tipoContorno=attributi.hasAttribute("tipoContorno") ? attributi.value("tipoContorno").toString().toStdString() : "";
                        insertElemento=new contorno(nome,vegano,glutenFree,prezzoBase,urlImmagine,tipoContorno);
                    }
                    //inserisco elemento nel mio contenitore
                    if(insertElemento!=nullptr) {
                        piatti->pushEnd(insertElemento);
                    }
                    //passo ad elemento successivo
                    if(!xmlReader.isEndDocument())
                        xmlReader.skipCurrentElement();

                }
            }

        }

        elementiMenu.close();
}

//Salvo dati menu su file XML
void modello::salvataggioDati(){
    QSaveFile elementoMenu(QString::fromStdString(xmlFile));

    if(!elementoMenu.open(QIODevice::WriteOnly))
        return;

    QXmlStreamWriter xmlWriter(&elementoMenu);
    //leggibilita XML
    xmlWriter.setAutoFormatting(true);
    //scrittura intezstazioni
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("root");

    container<piattoBase*>::iteratore it = mBegin();

    while(it != mEnd()){
        const piattoBase* insert = *it;
        primo* p=dynamic_cast<primo*>(*it);
        secondo* s=dynamic_cast<secondo*>(*it);
        contorno* c=dynamic_cast<contorno*>(*it);

        if(p) {
            xmlWriter.writeEmptyElement("primo");
            xmlWriter.writeAttribute("nome", QString::fromStdString(insert->getNome()));
            xmlWriter.writeAttribute("vegano", p->isVegano() ? "true" : "false");
            xmlWriter.writeAttribute("glutenFree", p->isVegano() ? "true" : "false");
            xmlWriter.writeAttribute("prezzoBase", QString("%1").arg(p->getPrezzoBase()));
            xmlWriter.writeAttribute("urlImmagine", QString::fromStdString(insert->getUrlImmagine()));
            xmlWriter.writeAttribute("soia", p->isVegano() ? "true" : "false");
            xmlWriter.writeAttribute("tipoPasta", QString::fromStdString(p->getPasta()));
            xmlWriter.writeAttribute("condimento", QString::fromStdString(p->getCondimento()));
            xmlWriter.writeAttribute("ingrediente1", QString::fromStdString(p->getIngrediente1()));
            xmlWriter.writeAttribute("ingrediente2", QString::fromStdString(p->getIngrediente2()));
            xmlWriter.writeAttribute("ingrediente3", QString::fromStdString(p->getIngrediente3()));
        }
        if(s) {
            xmlWriter.writeEmptyElement("secondo");
            xmlWriter.writeAttribute("nome", QString::fromStdString(s->getNome()));
            xmlWriter.writeAttribute("vegano", s->isVegano() ? "true" : "false");
            xmlWriter.writeAttribute("glutenFree", s->isVegano() ? "true" : "false");
            xmlWriter.writeAttribute("prezzoBase", QString("%1").arg(s->getPrezzoBase()));
            xmlWriter.writeAttribute("urlImmagine", QString::fromStdString(insert->getUrlImmagine()));
            xmlWriter.writeAttribute("tipoCarnePesce", QString::fromStdString(s->getTipoCarnePesce()));
            xmlWriter.writeAttribute("tipoPiatto", QString::fromStdString(s->getTipoPiatto()));
        }
        if(c) {
            xmlWriter.writeEmptyElement("contorno");
            xmlWriter.writeAttribute("nome", QString::fromStdString(c->getNome()));
            xmlWriter.writeAttribute("vegano", c->isVegano() ? "true" : "false");
            xmlWriter.writeAttribute("glutenFree", c->isVegano() ? "true" : "false");
            xmlWriter.writeAttribute("prezzoBase", QString("%1").arg(c->getPrezzoBase()));
            xmlWriter.writeAttribute("urlImmagine", QString::fromStdString(insert->getUrlImmagine()));
            xmlWriter.writeAttribute("tipoContorno", QString::fromStdString(c->getTipoContorno()));
        }
         ++it;
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    //datiSalvati = true;
    elementoMenu.commit();
}

//Begin e End modello
container<piattoBase*>::iteratore modello::mBegin() {
    return piatti->begin();
}
container<piattoBase *>::iteratore modello::mEnd() {
    return piatti->end();
}
//Get lista modello
container<piattoBase*>*modello::getLista() const {
    if(piatti)
        return piatti;
    else
        return nullptr;
}
//erase modello

void modello::mErase(container<piattoBase*>::iteratore it) {
    piatti->erase(it);
}



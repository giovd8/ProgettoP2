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
modello::modello(string s):
    piatti(new container<piattoBase*>),
    xmlFile(s)
//    datiSalvati(true)
{}

modello::~modello() {
    delete piatti;
}

container<piattoBase*>*modello::getLista() const {
    return piatti;
}

void modello::setNuovoPercorso(string p)
{
    xmlFile = p;
    delete piatti;
    //    datiSalvati = false;
    piatti=new container<piattoBase*>();
}

//Begin e End modello
container<piattoBase*>::iteratore modello::mBegin()
{
    return piatti->begin();
}
container<piattoBase *>::iteratore modello::mEnd()
{
    return piatti->end();
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
                    piattoBase* insertElemento=nullptr;
                    //prendo attributi primo
                    if(xmlReader.name()=="primo"){
                        bool soia=attributi.hasAttribute("soia") ? attributi.value("soia").toString()=="true"? true : false : false;
                        string tipoPatsa=attributi.hasAttribute("tipoPasta") ? attributi.value("tipoPasta").toString().toStdString() : "";
                        string ingrediente1=attributi.hasAttribute("ingrediente1") ? attributi.value("ingrediente1").toString().toStdString() : "";
                        string ingrediente2=attributi.hasAttribute("ingrediente2") ? attributi.value("ingrediente2").toString().toStdString() : "";
                        string ingrediente3=attributi.hasAttribute("ingrediente3") ? attributi.value("ingrediente3").toString().toStdString() : "";
                        string ingrediente4=attributi.hasAttribute("ingrediente4") ? attributi.value("ingrediente4").toString().toStdString() : "";
                        insertElemento=new primo(nome,vegano,glutenFree,prezzoBase,soia,tipoPatsa,ingrediente1,ingrediente2,ingrediente3,ingrediente4);
                    }
                    //prendo attributi secondo
                    if(xmlReader.name()=="secondo"){
                        string tipoCarne=attributi.hasAttribute("tipoCarne") ? attributi.value("tipoCarne").toString().toStdString() : "";
                        string tipoPesce=attributi.hasAttribute("tipoPesce") ? attributi.value("tipoPesce").toString().toStdString() : "";
                        string tipoPiatto=attributi.hasAttribute("tipoPiatto") ? attributi.value("tipoPiatto").toString().toStdString() : "";
                        string tipoCottura=attributi.hasAttribute("tipoCottura") ? attributi.value("tipoCottura").toString().toStdString() : "";
                        insertElemento=new secondo(nome,vegano,glutenFree,prezzoBase,tipoCarne,tipoPesce,tipoPiatto,tipoCottura);
                    }
                    //prendo attributi contorno
                    if(xmlReader.name()=="contorno"){
                        bool patate=attributi.hasAttribute("patate") ? attributi.value("patate").toString()=="true"? true : false : false;
                        string tipoContorno=attributi.hasAttribute("tipoContorno") ? attributi.value("tipoContorno").toString().toStdString() : "";
                        insertElemento=new contorno(nome,vegano,glutenFree,prezzoBase,patate,tipoContorno);
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



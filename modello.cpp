#include "modello.h"
#include"primo.h"
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <iostream>
using std::string;
using std::cout;

//costruttore e distruttore modello
modello::modello(std::string s):
    piatti(new container<piattoBase*>),
    xmlFile(s)
//    datiSalvati(true)
{}

modello::~modello(){delete piatti;}

void modello::caricamentoDati() const {
    QFile elementiMenu(QString::fromStdString(xmlFile));

    if(!elementiMenu.open(QIODevice::ReadOnly)) {
        qWarning() << "Impossibile caricare i piatti del menu!" << elementiMenu.errorString();
        return ;
    }

    QXmlStreamReader xmlReader(&elementiMenu);//variabile lettore
        if(xmlReader.readNextStartElement()){
            if(xmlReader.name() == "root"){
                while(xmlReader.readNextStartElement()){
                    const QXmlStreamAttributes attributi = xmlReader.attributes();
                    //prendo attributi piatto base
                    string nome=attributi.hasAttribute("nome") ? attributi.value("nome").toString().toStdString() : "";
                    bool vegano=attributi.hasAttribute("vegano") ? attributi.value("vegano").toString()=="true"? true : false : false;
                    bool glutenFree=attributi.hasAttribute("glutenFree") ? attributi.value("glutenFree").toString()=="true"? true : false : false;
                    double prezzoBase=attributi.hasAttribute("prezzoBase") ? attributi.value("prezzoBase").toString()=="true"? true : false : false;

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
                    //inserisco elemento nel mio contenitore
                    if(insertElemento!=nullptr)
                        piatti->pushEnd(insertElemento);
                }
            }

        }
        elementiMenu.close();
}


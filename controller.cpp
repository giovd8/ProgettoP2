#include "controller.h"

#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QtWidgets>
#include<QDebug>
#include"modello.h"
#include"contorno.h"
#include"piattobase.h"
#include<iostream>
using namespace std;

controller::controller(QWidget *parent):
    QWidget(parent),
    xmlFile(QFileDialog::getOpenFileName(this, tr("Scegli FIle"), "Progettop2/PiattiMenu", "File XML(*.xml)")),
    mp(new menuprincipale(this)),
    md(new modifichedati(this)),
    viewP(new viewpiatti(this))
//    ip(new inserimentoPiatto(this))
{
    //creo modello
    m=(new modello(xmlFile.toStdString()));
    //setto percorso
    m->nuovoPercorso(xmlFile.toStdString());
    //carico i dati da file xml e li metto nella mia lista
    m->caricamentoDati();

    QVBoxLayout* x=new QVBoxLayout;
    x->addWidget(mp);
    x->addWidget(md);
    x->addWidget(viewP);

    //connect pulsanti visualizzazione sottolista
    connect(viewP->getTuttiPiatti(), SIGNAL(clicked()), this, SLOT(caricaPiatti()));
    connect(viewP->getTuttiPrimi(), SIGNAL(clicked()), this, SLOT(caricaPrimi()));
    connect(viewP->getTuttiSecondi(), SIGNAL(clicked()), this, SLOT(caricaSecondi()));
    connect(viewP->getTuttiContorni(), SIGNAL(clicked()), this, SLOT(caricaContorni()));

    //connect pulsanti modifica/aggiungi/elimina piatto
    connect(md->getAggiungiPiatto(), SIGNAL(clicked()), this, SLOT(aggiungiPiatto()));

    setLayout(x);
}

    void controller::aggiungiPiatto(){
        QDialog* d=new inserimentoPiatto(m,this);
        d->show();
        //this->setDisabled(true);
    }

    //tutti i piatti
    void controller::caricaPiatti() const {
        if(xmlFile!="") {
            viewP->getLista()->clear();
            container<piattoBase*>::iteratore it = m->mBegin();
            for(; it!= m->mEnd(); ++it)
                viewP->getLista()->aggiungiPiatto(*it);
        }
    }
    //tutti i primi
    void controller::caricaPrimi() const {
        if(xmlFile!="") {
            viewP->getLista()->clear();
            container<piattoBase*>::iteratore it = m->mBegin();
            for(; it!= m->mEnd(); ++it){
                if(dynamic_cast<primo*>(*it))
                    viewP->getLista()->aggiungiPiatto(*it);
            }
        }
    }
    //tutti i secondi
    void controller::caricaSecondi() const {
        if(xmlFile!="") {
            viewP->getLista()->clear();
            container<piattoBase*>::iteratore it = m->mBegin();
            for(; it!= m->mEnd(); ++it){
                if(dynamic_cast<secondo*>(*it))
                    viewP->getLista()->aggiungiPiatto(*it);
            }
        }
    }
    //tutti i contorni
    void controller::caricaContorni() const {
        if(xmlFile!="") {
            viewP->getLista()->clear();
            container<piattoBase*>::iteratore it = m->mBegin();
            for(; it!= m->mEnd(); ++it){
                if(dynamic_cast<contorno*>(*it))
                    viewP->getLista()->aggiungiPiatto(*it);
            }
        }
    }



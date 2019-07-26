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

    //connect(viewP->getLista()->elem, SIGNAL(clicked()), this, SLOT(caricaDisable()));
    md->getModificaPiatto()->setEnabled(false);
    md->getEliminaPiatto()->setEnabled(false);

    //connect pulsanti modifica/aggiungi/elimina piatto
    connect(md->getAggiungiPiatto(), SIGNAL(clicked()), this, SLOT(aggiungiPiatto()));
    connect(md->getModificaPiatto(), SIGNAL(clicked()), this, SLOT(modPiatto()));
    connect(md->getEliminaPiatto(), SIGNAL(clicked()), this, SLOT(eliminaPiatto()));
    connect(viewP->getLista(), SIGNAL(itemSelectionChanged()), this, SLOT(gestisciPulsantiModElim()));

    this->resize(500,650);
    setLayout(x);
}
//visualizza tutti i piatti
void controller::caricaPiatti() const {
    if(xmlFile!="") {
        viewP->getLista()->clear();
        container<piattoBase*>::iteratore it = m->mBegin();
        for(; it!= m->mEnd(); ++it)
            viewP->getLista()->aggiungiPiatto(*it);
        md->getModificaPiatto()->setEnabled(false);
        md->getEliminaPiatto()->setEnabled(false);
    }
}
//visualizza tutti i primi
void controller::caricaPrimi() const {
    if(xmlFile!="") {
        viewP->getLista()->clear();
        container<piattoBase*>::iteratore it = m->mBegin();
        for(; it!= m->mEnd(); ++it){
            if(dynamic_cast<primo*>(*it))
                viewP->getLista()->aggiungiPiatto(*it);
        }
        md->getModificaPiatto()->setEnabled(false);
        md->getEliminaPiatto()->setEnabled(false);
    }
}
//visualizza tutti i secondi
void controller::caricaSecondi() const {
    if(xmlFile!="") {
        viewP->getLista()->clear();
        container<piattoBase*>::iteratore it = m->mBegin();
        for(; it!= m->mEnd(); ++it){
            if(dynamic_cast<secondo*>(*it))
                viewP->getLista()->aggiungiPiatto(*it);
        }
        md->getModificaPiatto()->setEnabled(false);
        md->getEliminaPiatto()->setEnabled(false);
    }
}
//visualizza tutti i contorni
void controller::caricaContorni() const {
    if(xmlFile!="") {
        viewP->getLista()->clear();
        container<piattoBase*>::iteratore it = m->mBegin();
        for(; it!= m->mEnd(); ++it){
            if(dynamic_cast<contorno*>(*it))
                viewP->getLista()->aggiungiPiatto(*it);
        }
        md->getModificaPiatto()->setEnabled(false);
        md->getEliminaPiatto()->setEnabled(false);
    }
}
//gestisci pulsanti
void controller::gestisciPulsantiModElim() const {
    md->getModificaPiatto()->setEnabled(true);
    md->getEliminaPiatto()->setEnabled(true);
}

//aggiungi piatto
void controller::aggiungiPiatto(){
    QDialog* d=new inserimentoPiatto(m,this);
    //mostra la finesta e disabilita quella sotto
    d->exec();
    caricaPiatti();
}

//modifica piatto
void controller::modPiatto(){
    elementiListaP* lc=viewP->getLista()->piattoCorrente();
    piattoBase* pb=lc->prelevaPiatto();
    if(pb!=nullptr){
        container<piattoBase*>::iteratore it=m->mBegin();
        bool trovato=false;
        for(;it!=m->mEnd() && !trovato;++it) {
            if(*it==pb) {
                trovato=true;
                QDialog* d=new modificaPiatto(m,*it,this);
                d->resize(500,300);
                d->exec();
            }
         }
    }
    caricaPiatti();
}

//elimina piatto
void controller::eliminaPiatto(){
    elementiListaP* lc=viewP->getLista()->piattoCorrente();
    piattoBase* pb=lc->prelevaPiatto();
    if(pb!=nullptr){
        container<piattoBase*>::iteratore it=m->mBegin();
        for(;it!=m->mEnd();++it) {
            if(*it==pb) {
                bool p=false;
                bool s=false;
                if(dynamic_cast<primo*>(*it)) {
                    p=true;
                }
                else {
                    if(dynamic_cast<secondo*>(*it))
                        s=true;
                }
                m->mErase(it);
                delete(*it);
                --it;
                m->caricaOggettoXML();
                QMessageBox::warning(this,"Eliminazione completata", "Il piatto e stato eliminato carrettamente!");
                if(p) {
                    caricaPrimi();
                }
                else {
                    if(s)
                        caricaSecondi();
                    else
                        caricaContorni();
                }
            }
        }
    }
    else {
        QMessageBox::warning(this,"Errore", "Devi selezionare quale piatto vuoi eliminare!");
    }
}




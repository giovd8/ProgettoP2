#include "controller.h"

#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QtWidgets>
#include<QDebug>
#include<QLabel>
#include"modello.h"
#include"contorno.h"
#include"piattobase.h"
#include<iostream>

using namespace std;

controller::controller(QWidget *parent):
    QWidget(parent),
    xmlFile(QFileDialog::getOpenFileName(this, tr("Scegli File"), ":/piattiMenu", "File XML(*.xml)")),
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

    //imposto logo ristorante
    QHBoxLayout* logoContainer=new QHBoxLayout;
    QPixmap logo(":/piattiMenu/immagini/logo.png");
    QLabel* logoCucu = new QLabel(this);
    logoCucu->setPixmap(logo.scaled(120, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    logoCucu->setStyleSheet("QLabel { margin: 0 auto; }");
    QLabel* presentazione = new QLabel("Modifica piatti principali menu ristorante");
    presentazione->setStyleSheet("QLabel { font: 20px; }");
    logoContainer->addWidget(logoCucu);
    logoContainer->addWidget(presentazione,Qt::AlignCenter);

    //imnposto view principale
    QVBoxLayout* x=new QVBoxLayout;
    x->addLayout(logoContainer);
    x->addWidget(viewP);
    x->addWidget(md);
    x->addWidget(mp);

    //viewController->addWidget(x);
    //parent->setStyleSheet("QVBoxLayout { Background-color: 5d5d5f; }");

    connect(mp->getSalva(),SIGNAL(clicked()), this, SLOT(salvaModello()));
    connect(mp->getClose(),SIGNAL(clicked()), this, SLOT(closeApp()));


    //connect pulsanti visualizzazione sottolista
    connect(viewP->getTuttiPiatti(), SIGNAL(clicked()), this, SLOT(caricaPiatti()));
    connect(viewP->getTuttiPrimi(), SIGNAL(clicked()), this, SLOT(caricaPrimi()));
    connect(viewP->getTuttiSecondi(), SIGNAL(clicked()), this, SLOT(caricaSecondi()));
    connect(viewP->getTuttiContorni(), SIGNAL(clicked()), this, SLOT(caricaContorni()));

    md->getModificaPiatto()->setEnabled(false);
    md->getEliminaPiatto()->setEnabled(false);

    //connect pulsanti modifica/aggiungi/elimina piatto
    connect(md->getAggiungiPiatto(), SIGNAL(clicked()), this, SLOT(aggiungiPiatto()));
    connect(md->getModificaPiatto(), SIGNAL(clicked()), this, SLOT(modPiatto()));
    connect(md->getEliminaPiatto(), SIGNAL(clicked()), this, SLOT(eliminaPiatto()));
    connect(md->getCercaPiatto(), SIGNAL(clicked()), this, SLOT(findPiatto()));
    connect(viewP->getLista(), SIGNAL(itemSelectionChanged()), this, SLOT(gestisciPulsantiModElim()));

    this->resize(600,600);
    setLayout(x);
}
//salvo dati menu su XML
void controller::salvaModello() {
    m->salvataggioDati();
    m->setSalvataggioEffetuato(true);
    QMessageBox::information(this,"Salvataggio completata", "Il menu e' stato carrettamente!");
}
//chiudo app
void controller::closeApp() {
    if(!m->getSalvataggioEffetuato()) {
        QMessageBox uss;
        uss.setText("Il menu è stato modificato!");
        uss.setInformativeText("\nVuoi salvare le modifiche prima di uscire?\n\n");
        uss.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        uss.setDefaultButton(QMessageBox::Save);
        uss.setEscapeButton(QMessageBox::Cancel);
        int choice=uss.exec();
        switch (choice) {
          case QMessageBox::Save:
                m->salvataggioDati();
                //m->setSalvataggioEffetuato(true);
                QApplication::quit();
          break;
          case QMessageBox::Discard:
               QApplication::quit();
          break;
          case QMessageBox::Cancel:
          break;
        }
     }
    else
        QApplication::quit();
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
    viewP->getLista()->scrollToTop();
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
    viewP->getLista()->scrollToTop();
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
    viewP->getLista()->scrollToTop();
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
    viewP->getLista()->scrollToTop();
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
        QDialog* d=new modificaPiatto(m,pb,this);
        d->resize(500,300);
        d->exec();
    }
    if(dynamic_cast<primo*>(pb))
        caricaPrimi();
    else {
        if(dynamic_cast<secondo*>(pb))
            caricaSecondi();
        else
            caricaContorni();
    }
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
                m->setSalvataggioEffetuato(false);
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
//cerca piatto
void controller::findPiatto(){
    QDialog* d=new cercaPiatto(m,viewP,this);
    d->exec();
}
//gestisci pulsanti
void controller::gestisciPulsantiModElim() const {
    md->getModificaPiatto()->setEnabled(true);
    md->getEliminaPiatto()->setEnabled(true);
}

void controller::closeEvent(QCloseEvent *event) {
    if (event->spontaneous()) {
        if(!m->getSalvataggioEffetuato()) {
            QMessageBox uss;
            uss.setText("Il menu è stato modificato!");
            uss.setInformativeText("\nVuoi salvare le modifiche prima di uscire?\n\n");
            uss.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
            uss.setDefaultButton(QMessageBox::Save);
            int choice=uss.exec();
            switch (choice) {
              case QMessageBox::Save:
                    m->salvataggioDati();
                    //m->setSalvataggioEffetuato(true);
                    QApplication::quit();
              break;
              case QMessageBox::Discard:
                   QApplication::quit();
              break;
            }
        }
        else
            QApplication::quit();
    }
    else {

    }
}

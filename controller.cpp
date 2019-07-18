#include "controller.h"

#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QtWidgets>
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
    m=(new modello(xmlFile.toStdString()));
    m->setNuovoPercorso(xmlFile.toStdString());
    m->caricamentoDati();

    QVBoxLayout* x=new QVBoxLayout;
    x->addWidget(mp);
    x->addWidget(md);
    x->addWidget(viewP);

    connect(viewP->getTuttiPiatti(), SIGNAL(clicked()), this, SLOT(caricaPiatti()));
    connect(viewP->getTuttiPrimi(), SIGNAL(clicked()), this, SLOT(caricaPiatti()));
    setLayout(x);
}

    void controller::caricaPiatti(){
        if(xmlFile!="") {
            container<piattoBase*>::iteratore it = m->mBegin();
            for(; it!= m->mEnd(); ++it){
//                piattoBase* x=new contorno("aaa",true,true,8,true,"sss");
                viewP->getLista()->aggiungiPiatto(*it);
            }

        }

    }



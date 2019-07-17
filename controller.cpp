#include "controller.h"

#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QtWidgets>
#include"modello.h"

controller::controller(QWidget *parent):
    QWidget(parent),
    xmlFile(QFileDialog::getOpenFileName(this, tr("Scegli FIle"), "Progettop2/PiattiMenu", "File XML(*.xml)")),
    mp(new menuprincipale(this)),
    md(new modifichedati(this)),
    vp(new viewprodotti(this))
{
    m=(new modello(xmlFile.toStdString()));
    m->caricamentoDati();
    QVBoxLayout* x=new QVBoxLayout;
    x->addWidget(mp);
    x->addWidget(md);
    x->addWidget(vp);

//    void controller::caricaPiatti(){
//        if(xmlFile!=""){//se il mio file non è vuoto
//            negl->getLista()->clear();//la  mia lista è derivata da qlistwidget posso usare il metodo derivato clear per pilure la lista prec

//            if(negl->getInfoBottoneTutte() == true) {//se ho premuto il tasto bottone tutto il negozio
//                Contenitore<itemBase*>::Constiterator citini = model->mcbegin();
//                Contenitore<itemBase*>::Constiterator citfine = model->mcend();
//                for(; citini != citfine ; ++citini){
//                        negl->getLista()->aggiungiItem(*citini);
//                }
//                negl->setFalseBottoneTutte();//setto a false il booleano nel negozio
//            }
//        }
//        negl->getBottoneElimina()->setEnabled(false);
//        negl->getBottoneModifica()->setEnabled(false);
//    }


//    connect(mp->getClose(),SIGNAL(clicked()),this,SLOT());

    setLayout(x);
}


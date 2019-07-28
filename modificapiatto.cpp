#include "modificapiatto.h"
#include<QDebug>


modificaPiatto::modificaPiatto(modello* mm, piattoBase* pMod, QWidget* d):
    QDialog(d),
    //piatto base
    nomeP(new QLabel("Nome:",this)),
    veganoP(new QLabel("Vegano:",this)),
    glutenFreeP(new QLabel("GlutenFree:",this)),
    prezzoBaseP(new QLabel("Prezzo:",this)),
    modificaNomeP(new QLineEdit(this)),
    modificaVeganoP(new QCheckBox(this)),
    modificaGlutenFreeP(new QCheckBox(this)),
    modificaPrezzoBaseP(new QLineEdit(this)),
    //primo piatto
    soiaP(new QLabel("Soia",this)),
    tipoPastaP(new QLabel("Tipo di pasta:",this)),
    condimentoP(new QLabel("Condimento:",this)),
    ingrediente1P(new QLabel("Ingrediente 1:",this)),
    ingrediente2P(new QLabel("Ingrediente 2:",this)),
    ingrediente3P(new QLabel("Ingrediente 3:",this)),
    modificaSoiaP(new QCheckBox(this)),
    modificaTipoPastaP(new QLineEdit(this)),
    modificaCondimentoP(new QLineEdit(this)),
    modificaIngrediente1P(new QLineEdit(this)),
    modificaIngrediente2P(new QLineEdit(this)),
    modificaIngrediente3P(new QLineEdit(this)),
    //secondo piatto
    tipoCarneP(new QLabel("Tipo di carne:",this)),
    tipoPesceP(new QLabel("Tipo di pesce:",this)),
    tipoPiattoP(new QLabel("Tipo piatto:",this)),
    tipoCotturaP(new QLabel("Tipo cottura:",this)),
    modificaTipoCarneP(new QLineEdit(this)),
    modificaTipoPesceP(new QLineEdit(this)),
    modificaTipoPiattoP(new QLineEdit(this)),
    modificaTipoCotturaP(new QLineEdit(this)),
    //contorni
    tipoNomeContornoP(new QLabel("Contorno:",this)),
    tipoContornoP(new QLabel("Tipologia contorno:",this)),
    modificaTipoNomeContornoP(new QLineEdit(this)),
    modificaTipoContornoP(new QLineEdit(this)),
    //view dinamiche
    primiView(new QWidget(this)),
    secondiView(new QWidget(this)),
    contorniView(new QWidget(this)),
    //pulsanti Modifica chiudi
    modificaP(new QPushButton("Modifica",this)),
    close(new QPushButton("Annulla",this)),
    //caricamento modello
    m(mm),
    pb(pMod)
{
    //griglia principale
    QGridLayout* mainView = new QGridLayout;
    //widget modifica
    QWidget* piattoBaseView = new QWidget(this);

    //inserisco i widget piatto base nella sottogriglia con il valore precedente
    QGridLayout* listaModificaPiattoBase = new QGridLayout;
    listaModificaPiattoBase->addWidget(nomeP,0,0,1,1);
    listaModificaPiattoBase->addWidget(modificaNomeP,0,1,1,1);
    modificaNomeP->setText(QString::fromStdString(pMod->getNome()));
    listaModificaPiattoBase->addWidget(veganoP,1,0,1,1);
    listaModificaPiattoBase->addWidget(modificaVeganoP,1,1,1,1);
    if(pMod->isVegano())
        modificaVeganoP->setCheckState(Qt::CheckState(true));
    else
        modificaVeganoP->setCheckState(Qt::CheckState(false));
    listaModificaPiattoBase->addWidget(glutenFreeP,2,0,1,1);
    listaModificaPiattoBase->addWidget(modificaGlutenFreeP,2,1,1,1);
    if(pMod->isGlutenFree())
        modificaGlutenFreeP->setCheckState(Qt::CheckState(true));
    else
        modificaGlutenFreeP->setCheckState(Qt::CheckState(false));
    listaModificaPiattoBase->addWidget(prezzoBaseP,3,0,1,1);
    listaModificaPiattoBase->addWidget(modificaPrezzoBaseP,3,1,1,1);
    modificaPrezzoBaseP->setText(QString::number(pMod->getPrezzoBase()));
    piattoBaseView->setLayout(listaModificaPiattoBase);
    mainView->addWidget(piattoBaseView,1,0,1,1);
    primo* x=dynamic_cast<primo*>(pMod);
    if(x) {
        //inserisco i widget primo piatto nella sottogriglia
        QGridLayout* listaModificaPrimi = new QGridLayout;
        listaModificaPrimi->addWidget(soiaP,0,0,1,1);
        listaModificaPrimi->addWidget(modificaSoiaP,0,1,1,1);
        if(x->isSoia())
            modificaSoiaP->setCheckState(Qt::CheckState(true));
        else
            modificaSoiaP->setCheckState(Qt::CheckState(false));
        listaModificaPrimi->addWidget(tipoPastaP,1,0,1,1);
        listaModificaPrimi->addWidget(modificaTipoPastaP,1,1,1,1);
        modificaTipoPastaP->setText(QString::fromStdString(x->getPasta()));
        listaModificaPrimi->addWidget(condimentoP,2,0,1,1);
        listaModificaPrimi->addWidget(modificaCondimentoP,2,1,1,1);
        modificaCondimentoP->setText(QString::fromStdString(x->getCondimento()));
        listaModificaPrimi->addWidget(ingrediente1P,3,0,1,1);
        listaModificaPrimi->addWidget(modificaIngrediente1P,3,1,1,1);
        modificaIngrediente1P->setText(QString::fromStdString(x->getIngrediente1()));
        listaModificaPrimi->addWidget(ingrediente2P,4,0,1,1);
        listaModificaPrimi->addWidget(modificaIngrediente2P,4,1,1,1);
        modificaIngrediente2P->setText(QString::fromStdString(x->getIngrediente2()));
        listaModificaPrimi->addWidget(ingrediente3P,5,0,1,1);
        listaModificaPrimi->addWidget(modificaIngrediente3P,5,1,1,1);
        modificaIngrediente3P->setText(QString::fromStdString(x->getIngrediente3()));
        primiView->setLayout(listaModificaPrimi);
        mainView->addWidget(primiView,2,0,1,1);
    }
    secondo* y=dynamic_cast<secondo*>(pMod);
    if(y){
        //inserisco i widget secondo piatto nella sottogriglia
        QGridLayout* listaModificaSecondi = new QGridLayout;
        listaModificaSecondi->addWidget(tipoCarneP,0,0,1,1);
        listaModificaSecondi->addWidget(modificaTipoCarneP,0,1,1,1);
        modificaTipoCarneP->setText(QString::fromStdString(y->getTipoCarne()));
        listaModificaSecondi->addWidget(tipoPesceP,1,0,1,1);
        listaModificaSecondi->addWidget(modificaTipoPesceP,1,1,1,1);
        modificaTipoPesceP->setText(QString::fromStdString(y->getTipoPesce()));
        listaModificaSecondi->addWidget(tipoPiattoP,2,0,1,1);
        listaModificaSecondi->addWidget(modificaTipoPiattoP,2,1,1,1);
        modificaTipoPiattoP->setText(QString::fromStdString(y->getTipoPiatto()));
        secondiView->setLayout(listaModificaSecondi);
        mainView->addWidget(secondiView,2,0,1,1);
    }
    contorno* z=dynamic_cast<contorno*>(pMod);
    if(z){
        //inserisco i widget contorno nella sottogriglia
        QGridLayout* listaModificaContorni = new QGridLayout;
        listaModificaContorni->addWidget(tipoNomeContornoP,0,0,1,1);
        listaModificaContorni->addWidget(modificaTipoNomeContornoP,0,1,1,1);
        modificaTipoNomeContornoP->setText(QString::fromStdString(z->getNomeContorno()));
        listaModificaContorni->addWidget(tipoContornoP,1,0,1,1);
        listaModificaContorni->addWidget(modificaTipoContornoP,1,1,1,1);
        modificaTipoContornoP->setText(QString::fromStdString(z->getTipoContorno()));
        contorniView->setLayout(listaModificaContorni);
        mainView->addWidget(contorniView,2,0,1,1);
    }

    //inserisco pulsanti Modifica/chiudi
    QHBoxLayout* q=new QHBoxLayout;
    q->addWidget(modificaP);
    q->addWidget(close);
    mainView->addLayout(q,3,0,1,1);

    if(x){
        primiView->show();
        secondiView->hide();
        contorniView->hide();
    }
    else {
        if(y){
            primiView->hide();
            secondiView->show();
            contorniView->hide();
        }
        else {
            primiView->hide();
            secondiView->hide();
            contorniView->show();
        }
    }

    modificaP->setDefault(true);

    //connect pulsanti
    connect(modificaP,SIGNAL(clicked()),this,SLOT(buttonModificaP()));
    connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));
    setLayout(mainView);
}

bool modificaPiatto::modificaPiattoCorrente(piattoBase* mod){
    bool modifica=false;
    //piatto base
    string nomeNewP=(modificaNomeP->text()).toLocal8Bit().constData();
    mod->setNome(nomeNewP);
    mod->setVegano(false);
    mod->setGlutenFree(false);
    if (modificaVeganoP->isChecked())
        mod->setVegano(true);
    if (modificaGlutenFreeP->isChecked())
        mod->setGlutenFree(true);
    string prezzoTemp=(modificaPrezzoBaseP->text()).toLocal8Bit().constData();
    double prezzoBaseNewP = atof(prezzoTemp.c_str());
    mod->setPrezzoBase(prezzoBaseNewP);
    //primo
    primo* p=dynamic_cast<primo*>(mod);
    if(p){
        p->setSoia(false);
        if (modificaSoiaP->isChecked())
            p->setSoia(true);
        string tipoPastaNewP=(modificaTipoPastaP->text()).toLocal8Bit().constData();
        string condimentoNewP=(modificaCondimentoP->text()).toLocal8Bit().constData();
        string ingrediente1NewP=(modificaIngrediente1P->text()).toLocal8Bit().constData();
        string ingrediente2NewP=(modificaIngrediente2P->text()).toLocal8Bit().constData();
        string ingrediente3NewP=(modificaIngrediente3P->text()).toLocal8Bit().constData();
        if(nomeNewP=="" || tipoPastaNewP=="" || condimentoNewP=="")
            QMessageBox::warning(this,"Modifica non riuscita", "ERRORE: Nome, tipo di pasta ed il condimento sono necessari!");
        else {
            p->setPasta(tipoPastaNewP);
            p->setCondimento(condimentoNewP);
            p->setIngrediente1(ingrediente1NewP);
            p->setIngrediente2(ingrediente2NewP);
            p->setIngrediente3(ingrediente3NewP);
            modifica=true;
        }
    }
    //secondo
    secondo* s=dynamic_cast<secondo*>(mod);
    if(s) {
        string tipoCarneNewP=(modificaTipoCarneP->text()).toLocal8Bit().constData();
        string tipoPesceNewP=(modificaTipoPesceP->text()).toLocal8Bit().constData();
        bool CoP=true;
        if((tipoCarneNewP!="" && tipoPesceNewP!="")||(tipoCarneNewP=="" && tipoPesceNewP=="")) {
            CoP=false;
            QMessageBox::warning(this,"Errore", "Inserire o tipo di carne o tipo di pesce, non entrambi!");
        }
        else {
            s->setTipoCarne(tipoCarneNewP);
            s->setTipoPesce(tipoPesceNewP);
        }
        string tipoPiattoNewP=(modificaTipoPiattoP->text()).toLocal8Bit().constData();
        if(!CoP && (nomeNewP=="" || prezzoBaseNewP==0 || (tipoCarneNewP=="" && tipoPesceNewP=="") || tipoPiattoNewP==""))
            QMessageBox::warning(this,"Modifica non riuscita", "ERRORE: Nome, prezzo base, tipo di carne o pesce e la tipologia del piatto sono necessari!");
        else {
            s->setTipoPiatto(tipoPiattoNewP);
            modifica=true;
        }
    }
    //contorno
    contorno* c=dynamic_cast<contorno*>(mod);
    if(contorniView->isVisible()) {
        string nomeContornoNewP=(modificaTipoNomeContornoP->text()).toLocal8Bit().constData();
        string tipoContornoNewP=(modificaTipoContornoP->text()).toLocal8Bit().constData();
        if(nomeNewP=="" || nomeContornoNewP=="" || tipoContornoNewP=="")
            QMessageBox::warning(this,"Modifica non riuscita", "ERRORE: Nome, tipo di carne o pesce e la tipologia del piatto sono necessari!");
        else {
            c->setNomeContorno(nomeContornoNewP);
            c->setTipoContorno(tipoContornoNewP);
            modifica=true;
        }
    }
    return modifica;
}

void modificaPiatto::buttonModificaP(){
    bool modifica=modificaPiatto::modificaPiattoCorrente(pb);
    if(modifica) {
       // m->caricaOggettoXML();
        QMessageBox::warning(this, "Modifica completata", "Il piatto e stato modificato correttamente!");
    }
    else
        QMessageBox::warning(this, "Errore", "Il piatto non e stato modificato vista la presenza di errori!");
    modificaPiatto::accept();
}
void modificaPiatto::buttonChiusura(){
   modificaPiatto::reject();
}

#include "modificapiatto.h"
#include<QDebug>

modificaPiatto::modificaPiatto(modello* mm, QWidget* d):
    QDialog(d),
    //bottoni selezione Modifica
    primiB(new QPushButton("Inserisci primo",this)),
    secondiB(new QPushButton("Inserisci secondo",this)),
    contorniB(new QPushButton("Inserisci contorno",this)),
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
    ingrediente1P(new QLabel("Ingrediente 1:",this)),
    ingrediente2P(new QLabel("Ingrediente 2:",this)),
    ingrediente3P(new QLabel("Ingrediente 3:",this)),
    ingrediente4P(new QLabel("Ingrediente 4:",this)),
    modificaSoiaP(new QCheckBox(this)),
    modificaTipoPastaP(new QLineEdit(this)),
    modificaIngrediente1P(new QLineEdit(this)),
    modificaIngrediente2P(new QLineEdit(this)),
    modificaIngrediente3P(new QLineEdit(this)),
    modificaIngrediente4P(new QLineEdit(this)),
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
    ModificaP(new QPushButton("Modifica",this)),
    close(new QPushButton("Esci",this)),
    //caricamento modello
    m(mm)
{
    //griglia principale
    QGridLayout* mainView = new QGridLayout;
    //widget Modifica
    QWidget* piattoBaseView = new QWidget(this);
    //tasti selezione tipo prodotto da aggiungere
    QHBoxLayout* x=new QHBoxLayout;
    x->addWidget(primiB);
    x->addWidget(secondiB);
    x->addWidget(contorniB);
    mainView->addLayout(x,1,0,1,1);

    //primiB->setFocusPolicy(Qt::NoFocus);
    //::setFocusPolicy(Qt::NoFocus);

    //inserisco i widget piatto base nella sottogriglia
    QGridLayout* listaModificaPiattoBase = new QGridLayout;
    listaModificaPiattoBase->addWidget(nomeP,0,0,1,1);
    listaModificaPiattoBase->addWidget(modificaNomeP,0,1,1,1);
    listaModificaPiattoBase->addWidget(veganoP,1,0,1,1);
    listaModificaPiattoBase->addWidget(modificaVeganoP,1,1,1,1);
    listaModificaPiattoBase->addWidget(glutenFreeP,2,0,1,1);
    listaModificaPiattoBase->addWidget(modificaGlutenFreeP,2,1,1,1);
    listaModificaPiattoBase->addWidget(prezzoBaseP,3,0,1,1);
    listaModificaPiattoBase->addWidget(modificaPrezzoBaseP,3,1,1,1);
    piattoBaseView->setLayout(listaModificaPiattoBase);
    mainView->addWidget(piattoBaseView,2,0,1,1);

    //inserisco i widget primo piatto nella sottogriglia
    QGridLayout* listaModificaPrimi = new QGridLayout;
    listaModificaPrimi->addWidget(soiaP,0,0,1,1);
    listaModificaPrimi->addWidget(modificaSoiaP,0,1,1,1);
    listaModificaPrimi->addWidget(tipoPastaP,1,0,1,1);
    listaModificaPrimi->addWidget(modificaTipoPastaP,1,1,1,1);
    listaModificaPrimi->addWidget(ingrediente1P,2,0,1,1);
    listaModificaPrimi->addWidget(modificaIngrediente1P,2,1,1,1);
    listaModificaPrimi->addWidget(ingrediente2P,3,0,1,1);
    listaModificaPrimi->addWidget(modificaIngrediente2P,3,1,1,1);
    listaModificaPrimi->addWidget(ingrediente3P,4,0,1,1);
    listaModificaPrimi->addWidget(modificaIngrediente3P,4,1,1,1);
    listaModificaPrimi->addWidget(ingrediente4P,5,0,1,1);
    listaModificaPrimi->addWidget(modificaIngrediente4P,5,1,1,1);
    primiView->setLayout(listaModificaPrimi);
    mainView->addWidget(primiView,3,0,1,1);

    //inserisco i widget secondo piatto nella sottogriglia
    QGridLayout* listaModificaSecondi = new QGridLayout;
    listaModificaSecondi->addWidget(tipoCarneP,0,0,1,1);
    listaModificaSecondi->addWidget(modificaTipoCarneP,0,1,1,1);
    listaModificaSecondi->addWidget(tipoPesceP,1,0,1,1);
    listaModificaSecondi->addWidget(modificaTipoPesceP,1,1,1,1);
    listaModificaSecondi->addWidget(tipoPiattoP,2,0,1,1);
    listaModificaSecondi->addWidget(modificaTipoPiattoP,2,1,1,1);
    listaModificaSecondi->addWidget(tipoCotturaP,3,0,1,1);
    listaModificaSecondi->addWidget(modificaTipoCotturaP,3,1,1,1);
    secondiView->setLayout(listaModificaSecondi);
    mainView->addWidget(secondiView,3,0,1,1);

    //inserisco i widget contorno nella sottogriglia
    QGridLayout* listaModificaContorni = new QGridLayout;
    listaModificaContorni->addWidget(tipoNomeContornoP,0,0,1,1);
    listaModificaContorni->addWidget(modificaTipoNomeContornoP,0,1,1,1);
    listaModificaContorni->addWidget(tipoContornoP,1,0,1,1);
    listaModificaContorni->addWidget(modificaTipoContornoP,1,1,1,1);
    contorniView->setLayout(listaModificaContorni);
    mainView->addWidget(contorniView,3,0,1,1);

    //imposto dati oggetto da modificare
    //modificaNomeP->setText(QString::fromStdString(oggModifica->getTitolo()));

    //inserisco pulsanti Modifica/chiudi
    QHBoxLayout* q=new QHBoxLayout;
    q->addWidget(ModificaP);
    q->addWidget(close);
    mainView->addLayout(q,4,0,1,1);

    primiView->show();
    secondiView->hide();
    contorniView->hide();

    //connect pulsanti
    connect(primiB,SIGNAL(clicked()),this,SLOT(buttonModificaPrimo()));
    connect(secondiB,SIGNAL(clicked()),this,SLOT(buttonModificaSecondi()));
    connect(contorniB,SIGNAL(clicked()),this,SLOT(buttonModificaContorni()));
    connect(ModificaP,SIGNAL(clicked()),this,SLOT(buttonModificaP()));
    connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));
    connect(modificaTipoCarneP,SIGNAL(clicked()),this,SLOT(disablePesce()));

    //connect(modificaTipoCarneP,SIGNAL(textChanged(QString)),this,SLOT(disablePesce()));


    setLayout(mainView);
}

void modificaPiatto::buttonModificaPrimi(){
    primiView->show();
    secondiView->hide();
    contorniView->hide();
    qWarning()<<"Modifica primo";
}

void modificaPiatto::buttonModificaSecondi(){
    primiView->hide();
    secondiView->show();
    contorniView->hide();
}

void modificaPiatto::buttonModificaContorni(){
    primiView->hide();
    secondiView->hide();
    contorniView->show();
}

//void ModificaPiatto::disablePesce() {
//     setDisabled(modificaTipoPesceP);
//}

piattoBase* modificaPiatto::modificaNuovoPiatto(){
    string nomeNewP=(modificaNomeP->text()).toLocal8Bit().constData();
    bool veganoNewP=false;
    bool glutenFreeNewP=false;
    string prezzoTemp=(modificaPrezzoBaseP->text()).toLocal8Bit().constData();
    if (modificaVeganoP->isChecked())
        veganoNewP=true;
    if (modificaGlutenFreeP->isChecked())
        glutenFreeNewP=true;
    double prezzoBaseNewP = atof(prezzoTemp.c_str());

    //primo
    if(primiView->isVisible()){
        bool soiaNewP=false;
        if (modificaSoiaP->isChecked())
            soiaNewP=true;
        string tipoPastaNewP=(modificaTipoPastaP->text()).toLocal8Bit().constData();
        string ingrediente1NewP=(modificaIngrediente1P->text()).toLocal8Bit().constData();
        string ingrediente2NewP=(modificaIngrediente2P->text()).toLocal8Bit().constData();
        string ingrediente3NewP=(modificaIngrediente1P->text()).toLocal8Bit().constData();
        string ingrediente4NewP=(modificaIngrediente1P->text()).toLocal8Bit().constData();
        if(nomeNewP=="" || prezzoBaseNewP==0 || tipoPastaNewP=="" || ingrediente1NewP=="")
            QMessageBox::warning(this,"Modifica non riuscito", "ERRORE: Nome, prezzo base, tipo di pasta ed almeno il primo ingredinete sono necessari!");
        else
            return new primo(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,soiaNewP,tipoPastaNewP,ingrediente1NewP,ingrediente2NewP,ingrediente3NewP,ingrediente4NewP);
    }
    //secondo
    if(secondiView->isVisible()) {
        string tipoCarneNewP=(modificaTipoCarneP->text()).toLocal8Bit().constData();
        string tipoPesceNewP=(modificaTipoPesceP->text()).toLocal8Bit().constData();
        bool CoP=true;
        if((tipoCarneNewP!="" && tipoPesceNewP!="")||(tipoCarneNewP=="" && tipoPesceNewP=="")) {
            CoP=false;
            QMessageBox::warning(this,"Errore", "Inserire o tipo di carne o tipo di pesce, non entrambi!");
        }
        string tipoPiattoNewP=(modificaTipoPiattoP->text()).toLocal8Bit().constData();
        string tipoCotturaNewP=(modificaTipoCotturaP->text()).toLocal8Bit().constData();
        if(!CoP && (nomeNewP=="" || prezzoBaseNewP==0 || (tipoCarneNewP=="" && tipoPesceNewP=="") || tipoPiattoNewP==""))
            QMessageBox::warning(this,"Modifica non riuscito", "ERRORE: Nome, prezzo base, tipo di carne o pesce e la tipologia del piatto sono necessari!");
        else
            return new secondo(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,tipoCarneNewP,tipoPesceNewP,tipoPiattoNewP,tipoCotturaNewP);
    }
    //contorno
    if(contorniView->isVisible()) {
        string nomeContornoNewP=(modificaTipoNomeContornoP->text()).toLocal8Bit().constData();
        string tipoContornoNewP=(modificaTipoContornoP->text()).toLocal8Bit().constData();
        if(nomeNewP=="" || prezzoBaseNewP==0 || nomeContornoNewP=="" || tipoContornoNewP=="")
            QMessageBox::warning(this,"Modifica non riuscito", "ERRORE: Nome, prezzo base, tipo di carne o pesce e la tipologia del piatto sono necessari!");
        else
            return new contorno(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,nomeContornoNewP,tipoContornoNewP);
    }

    return nullptr;

}

void modificaPiatto::buttonModificaP(){
    piattoBase* temp=modificaNuovoPiatto();
    if(temp!=nullptr) {
        m->getLista()->pushEnd(temp);
        QMessageBox::warning(this, "Modifica completato", "Il nuovo piatto stato aggiuto correttamente alla lista!");
//        m->caricamentoDati();
        m->caricaOggettoXML();
    }
    modificaPiatto::accept();
}
void modificaPiatto::buttonChiusura(){
   modificaPiatto::reject();
}

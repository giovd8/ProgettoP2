#include "inserimentopiatto.h"
#include<QDebug>

inserimentoPiatto::inserimentoPiatto(modello* mm, QWidget* d):
    QDialog(d),
    //bottoni selezione inserimento
    primiB(new QPushButton("Inserisci primo",this)),
    secondiB(new QPushButton("Inserisci secondo",this)),
    contorniB(new QPushButton("Inserisci contorno",this)),
    //piatto base
    nomeP(new QLabel("Nome:",this)),
    veganoP(new QLabel("Vegano:",this)),
    glutenFreeP(new QLabel("GlutenFree:",this)),
    prezzoBaseP(new QLabel("Prezzo:",this)),
    insertNomeP(new QLineEdit(this)),
    insertVeganoP(new QCheckBox(this)),
    insertGlutenFreeP(new QCheckBox(this)),
    insertPrezzoBaseP(new QLineEdit(this)),
    //primo piatto
    soiaP(new QLabel("Soia",this)),
    tipoPastaP(new QLabel("Tipo di pasta:",this)),
    condimentoP(new QLabel("Condimento:",this)),
    ingrediente1P(new QLabel("Ingrediente 1:",this)),
    ingrediente2P(new QLabel("Ingrediente 2:",this)),
    ingrediente3P(new QLabel("Ingrediente 3:",this)),
    insertSoiaP(new QCheckBox(this)),
    insertTipoPastaP(new QLineEdit(this)),
    insertCondimentoP(new QLineEdit(this)),
    insertIngrediente1P(new QLineEdit(this)),
    insertIngrediente2P(new QLineEdit(this)),
    insertIngrediente3P(new QLineEdit(this)),
    //secondo piatto
    tipoCarneP(new QLabel("Tipo di carne:",this)),
    tipoPesceP(new QLabel("Tipo di pesce:",this)),
    tipoPiattoP(new QLabel("Tipo piatto:",this)),
    insertTipoCarneP(new QLineEdit(this)),
    insertTipoPesceP(new QLineEdit(this)),
    insertTipoPiattoP(new QLineEdit(this)),
    //contorni
    tipoNomeContornoP(new QLabel("Contorno:",this)),
    tipoContornoP(new QLabel("Tipologia contorno:",this)),
    insertTipoNomeContornoP(new QLineEdit(this)),
    insertTipoContornoP(new QLineEdit(this)),
    //view dinamiche
    primiView(new QWidget(this)),
    secondiView(new QWidget(this)),
    contorniView(new QWidget(this)),
    //pulsanti aggiungi chiudi
    aggiungiP(new QPushButton("Aggiungi",this)),
    close(new QPushButton("Annulla",this)),
    //caricamento modello
    m(mm)
{
    //griglia principale
    QGridLayout* mainView = new QGridLayout;
    //widget inserimento
    QWidget* piattoBaseView = new QWidget(this);
    //tasti selezione tipo prodotto da aggiungere
    QHBoxLayout* x=new QHBoxLayout;
    x->addWidget(primiB);
    x->addWidget(secondiB);
    x->addWidget(contorniB);
    mainView->addLayout(x,1,0,1,1);

    //inserisco i widget piatto base nella sottogriglia
    QGridLayout* listaInserimentoPiattoBase = new QGridLayout;
    listaInserimentoPiattoBase->addWidget(nomeP,0,0,1,1);
    listaInserimentoPiattoBase->addWidget(insertNomeP,0,1,1,1);
    listaInserimentoPiattoBase->addWidget(veganoP,1,0,1,1);
    listaInserimentoPiattoBase->addWidget(insertVeganoP,1,1,1,1);
    listaInserimentoPiattoBase->addWidget(glutenFreeP,2,0,1,1);
    listaInserimentoPiattoBase->addWidget(insertGlutenFreeP,2,1,1,1);
    listaInserimentoPiattoBase->addWidget(prezzoBaseP,3,0,1,1);
    listaInserimentoPiattoBase->addWidget(insertPrezzoBaseP,3,1,1,1);
    piattoBaseView->setLayout(listaInserimentoPiattoBase);
    mainView->addWidget(piattoBaseView,2,0,1,1);

    //inserisco i widget primo piatto nella sottogriglia
    QGridLayout* listaInserimentoPrimi = new QGridLayout;
    listaInserimentoPrimi->addWidget(soiaP,0,0,1,1);
    listaInserimentoPrimi->addWidget(insertSoiaP,0,1,1,1);
    listaInserimentoPrimi->addWidget(tipoPastaP,1,0,1,1);
    listaInserimentoPrimi->addWidget(insertTipoPastaP,1,1,1,1);
    listaInserimentoPrimi->addWidget(condimentoP,2,0,1,1);
    listaInserimentoPrimi->addWidget(insertCondimentoP,2,1,1,1);
    listaInserimentoPrimi->addWidget(ingrediente1P,3,0,1,1);
    listaInserimentoPrimi->addWidget(insertIngrediente1P,3,1,1,1);
    listaInserimentoPrimi->addWidget(ingrediente2P,4,0,1,1);
    listaInserimentoPrimi->addWidget(insertIngrediente2P,4,1,1,1);
    listaInserimentoPrimi->addWidget(ingrediente3P,5,0,1,1);
    listaInserimentoPrimi->addWidget(insertIngrediente3P,5,1,1,1);
    primiView->setLayout(listaInserimentoPrimi);
    mainView->addWidget(primiView,3,0,1,1);

    //inserisco i widget secondo piatto nella sottogriglia
    QGridLayout* listaInserimentoSecondi = new QGridLayout;
    listaInserimentoSecondi->addWidget(tipoCarneP,0,0,1,1);
    listaInserimentoSecondi->addWidget(insertTipoCarneP,0,1,1,1);
    listaInserimentoSecondi->addWidget(tipoPesceP,1,0,1,1);
    listaInserimentoSecondi->addWidget(insertTipoPesceP,1,1,1,1);
    listaInserimentoSecondi->addWidget(tipoPiattoP,2,0,1,1);
    listaInserimentoSecondi->addWidget(insertTipoPiattoP,2,1,1,1);
    secondiView->setLayout(listaInserimentoSecondi);
    mainView->addWidget(secondiView,3,0,1,1);

    //inserisco i widget contorno nella sottogriglia
    QGridLayout* listaInserimentoContorni = new QGridLayout;
    listaInserimentoContorni->addWidget(tipoNomeContornoP,0,0,1,1);
    listaInserimentoContorni->addWidget(insertTipoNomeContornoP,0,1,1,1);
    listaInserimentoContorni->addWidget(tipoContornoP,1,0,1,1);
    listaInserimentoContorni->addWidget(insertTipoContornoP,1,1,1,1);
    contorniView->setLayout(listaInserimentoContorni);
    mainView->addWidget(contorniView,3,0,1,1);

    //inserisco pulsanti aggiungi/chiudi
    QHBoxLayout* q=new QHBoxLayout;
    q->addWidget(aggiungiP);
    q->addWidget(close);
    mainView->addLayout(q,4,0,1,1);

    primiView->show();
    secondiView->hide();
    contorniView->hide();

    aggiungiP->setDefault(true);

    //connect pulsanti
    connect(primiB,SIGNAL(clicked()),this,SLOT(buttonAggiungiPrimi()));
    connect(secondiB,SIGNAL(clicked()),this,SLOT(buttonAggiungiSecondi()));
    connect(contorniB,SIGNAL(clicked()),this,SLOT(buttonAggiungiContorni()));
    connect(aggiungiP,SIGNAL(clicked()),this,SLOT(buttonAggiungiP()));
    connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));

    //connect(insertTipoCarneP,SIGNAL(textChanged(QString)),this,SLOT(disablePesce()));


    setLayout(mainView);
}

void inserimentoPiatto::buttonAggiungiPrimi(){
    primiView->show();
    secondiView->hide();
    contorniView->hide();
}

void inserimentoPiatto::buttonAggiungiSecondi(){
    primiView->hide();
    secondiView->show();
    contorniView->hide();
}

void inserimentoPiatto::buttonAggiungiContorni(){
    primiView->hide();
    secondiView->hide();
    contorniView->show();
}

//void inserimentoPiatto::disablePesce() {
//     setDisabled(insertTipoPesceP);
//}

piattoBase* inserimentoPiatto::insertNuovoPiatto(){
    string nomeNewP=(insertNomeP->text()).toLocal8Bit().constData();
    bool veganoNewP=false;
    bool glutenFreeNewP=false;
    string prezzoTemp=(insertPrezzoBaseP->text()).toLocal8Bit().constData();
    if (insertVeganoP->isChecked())
        veganoNewP=true;
    if (insertGlutenFreeP->isChecked())
        glutenFreeNewP=true;
    double prezzoBaseNewP = atof(prezzoTemp.c_str());

    //primo
    if(primiView->isVisible()){
        bool soiaNewP=false;
        if (insertSoiaP->isChecked())
            soiaNewP=true;
        string tipoPastaNewP=(insertTipoPastaP->text()).toLocal8Bit().constData();
        string condimentoNewP=(insertCondimentoP->text()).toLocal8Bit().constData();
        string ingrediente1NewP=(insertIngrediente1P->text()).toLocal8Bit().constData();
        string ingrediente2NewP=(insertIngrediente2P->text()).toLocal8Bit().constData();
        string ingrediente3NewP=(insertIngrediente3P->text()).toLocal8Bit().constData();
        if(nomeNewP=="" || tipoPastaNewP=="" || condimentoNewP=="")
            QMessageBox::warning(this,"Inserimento non riuscito", "ERRORE: Nome, tipo di pasta ed il condimento sono necessari!");
        else
            return new primo(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,soiaNewP,tipoPastaNewP,condimentoNewP,ingrediente1NewP,ingrediente2NewP,ingrediente3NewP);
    }
    //secondo
    if(secondiView->isVisible()) {
        string tipoCarneNewP=(insertTipoCarneP->text()).toLocal8Bit().constData();
        string tipoPesceNewP=(insertTipoPesceP->text()).toLocal8Bit().constData();
        bool CoP=true;
        if((tipoCarneNewP!="" && tipoPesceNewP!="")||(tipoCarneNewP=="" && tipoPesceNewP=="")) {
            CoP=false;
            QMessageBox::warning(this,"Errore", "Inserire o tipo di carne o tipo di pesce, non entrambi!");
        }
        string tipoPiattoNewP=(insertTipoPiattoP->text()).toLocal8Bit().constData();
        if(!CoP && (nomeNewP=="" || (tipoCarneNewP=="" && tipoPesceNewP=="") || tipoPiattoNewP==""))
            QMessageBox::warning(this,"Inserimento non riuscito", "ERRORE: Nome, tipo di carne o pesce e la tipologia del piatto sono necessari!");
        else
            return new secondo(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,tipoCarneNewP,tipoPesceNewP,tipoPiattoNewP);
    }
    //contorno
    if(contorniView->isVisible()) {
        string nomeContornoNewP=(insertTipoNomeContornoP->text()).toLocal8Bit().constData();
        string tipoContornoNewP=(insertTipoContornoP->text()).toLocal8Bit().constData();
        if(nomeNewP=="" || nomeContornoNewP=="" || tipoContornoNewP=="")
            QMessageBox::warning(this,"Inserimento non riuscito", "ERRORE: Nome, tipo di carne o pesce e la tipologia del piatto sono necessari!");
        else
            return new contorno(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,nomeContornoNewP,tipoContornoNewP);
    }

    return nullptr;

}

void inserimentoPiatto::buttonAggiungiP(){
    piattoBase* temp=insertNuovoPiatto();
    if(temp!=nullptr) {
        m->getLista()->pushEnd(temp);
        QMessageBox::warning(this, "Inserimento completato", "Il nuovo piatto stato aggiuto correttamente alla lista!");
        //m->salvataggioDati();

    }
    inserimentoPiatto::accept();
}
void inserimentoPiatto::buttonChiusura(){
   inserimentoPiatto::reject();
}


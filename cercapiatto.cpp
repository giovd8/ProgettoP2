#include "cercapiatto.h"

cercaPiatto::cercaPiatto(modello* mm, viewpiatti* vp, QWidget* d):
    QDialog(d),
    //bottoni selezione cerca
    primiB(new QPushButton("Cerca primo",this)),
    secondiB(new QPushButton("Cerca secondo",this)),
    contorniB(new QPushButton("Cerca contorno",this)),
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
    tipoCarnePesceP(new QLabel("Tipo di carne o pesce:",this)),
    tipoPiattoP(new QLabel("Tipo cottura:",this)),
    insertTipoCarnePesceP(new QLineEdit(this)),
    insertTipoPiattoP(new QLineEdit(this)),
    //contorni
    tipoContornoP(new QLabel("Tipologia contorno:",this)),
    insertTipoContornoP(new QLineEdit(this)),
    //view dinamiche
    primiView(new QWidget(this)),
    secondiView(new QWidget(this)),
    contorniView(new QWidget(this)),
    //pulsanti aggiungi chiudi
    cercaP(new QPushButton("Cerca",this)),
    close(new QPushButton("Annulla",this)),
    //caricamento modello
    m(mm),
    y(vp)
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
    listaInserimentoSecondi->addWidget(tipoCarnePesceP,0,0,1,1);
    listaInserimentoSecondi->addWidget(insertTipoCarnePesceP,0,1,1,1);
    listaInserimentoSecondi->addWidget(tipoPiattoP,1,0,1,1);
    listaInserimentoSecondi->addWidget(insertTipoPiattoP,1,1,1,1);
    secondiView->setLayout(listaInserimentoSecondi);
    mainView->addWidget(secondiView,3,0,1,1);

    //inserisco i widget contorno nella sottogriglia
    QGridLayout* listaInserimentoContorni = new QGridLayout;
    listaInserimentoContorni->addWidget(tipoContornoP,0,0,1,1);
    listaInserimentoContorni->addWidget(insertTipoContornoP,0,1,1,1);
    contorniView->setLayout(listaInserimentoContorni);
    mainView->addWidget(contorniView,3,0,1,1);

    //inserisco pulsanti aggiungi/chiudi
    QHBoxLayout* q=new QHBoxLayout;
    q->addWidget(cercaP);
    q->addWidget(close);
    mainView->addLayout(q,4,0,1,1);

    primiView->show();
    secondiView->hide();
    contorniView->hide();

    cercaP->setDefault(true);

    //connect pulsanti
    connect(primiB,SIGNAL(clicked()),this,SLOT(buttonCercaPrimi()));
    connect(secondiB,SIGNAL(clicked()),this,SLOT(buttonCercaSecondi()));
    connect(contorniB,SIGNAL(clicked()),this,SLOT(buttonCercaContorni()));
    connect(cercaP,SIGNAL(clicked()),this,SLOT(buttonCercaP()));
    connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));

    setLayout(mainView);
}

void cercaPiatto::buttonCercaPrimi(){
    primiView->show();
    secondiView->hide();
    contorniView->hide();
}

void cercaPiatto::buttonCercaSecondi(){
    primiView->hide();
    secondiView->show();
    contorniView->hide();
}

void cercaPiatto::buttonCercaContorni(){
    primiView->hide();
    secondiView->hide();
    contorniView->show();
}

QPushButton* cercaPiatto::getCercaP() const{
    return cercaP;
}

piattoBase* cercaPiatto::creaPiattoTemp(){
    bool piattoBaseVuoto=false;
    string nomeNewP=(insertNomeP->text()).toLocal8Bit().constData();
    bool veganoNewP=false;
    bool glutenFreeNewP=false;
    string prezzoTemp=(insertPrezzoBaseP->text()).toLocal8Bit().constData();
    if (insertVeganoP->isChecked())
        veganoNewP=true;
    if (insertGlutenFreeP->isChecked())
        glutenFreeNewP=true;
    double prezzoBaseNewP = atof(prezzoTemp.c_str());
    if(nomeNewP=="" && veganoNewP==false && glutenFreeNewP==false && prezzoBaseNewP==0)
        piattoBaseVuoto=true;
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
        if(piattoBaseVuoto && tipoPastaNewP=="" && condimentoNewP=="" &&ingrediente1NewP=="" && ingrediente2NewP=="" && ingrediente3NewP=="")
            return nullptr;
        else
            return new primo(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,"",soiaNewP,tipoPastaNewP,condimentoNewP,ingrediente1NewP,ingrediente2NewP,ingrediente3NewP);
    }
    //secondo
    if(secondiView->isVisible()) {
        string tipoCarnePesceNewP=(insertTipoCarnePesceP->text()).toLocal8Bit().constData();
        string tipoPiattoNewP=(insertTipoPiattoP->text()).toLocal8Bit().constData();
        if(piattoBaseVuoto && tipoCarnePesceNewP=="" && tipoPiattoNewP=="")
            return nullptr;
        else
            return new secondo(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,"",tipoCarnePesceNewP,tipoPiattoNewP);
    }
    //contorno
    if(contorniView->isVisible()) {
        string tipoContornoNewP=(insertTipoContornoP->text()).toLocal8Bit().constData();
        if(piattoBaseVuoto && tipoContornoNewP=="")
            return nullptr;
        else
            return new contorno(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,"",tipoContornoNewP);
    }
   return nullptr;
}

void cercaPiatto::buttonCercaP(){
    piattoBase* temp=creaPiattoTemp();
    y->getLista()->clear();
    if(temp!=nullptr) {
        bool trovato=false;
        container<piattoBase*>::iteratore it=m->mBegin();
        for(; it!= m->mEnd(); ++it){
            if(*(*it)==*temp) {
                y->getLista()->aggiungiPiatto(*it);
                trovato=true;
            }
        }
        if(trovato)
            QMessageBox::information(this,"Trovato!", "Il piatto è stato trovato, verra visualizzato nella view principale!");

        else
            QMessageBox::information(this,"Non trovato!", "Il piatto non è stato trovato");
        delete temp;
    }
    else
        QMessageBox::warning(this,"Errore!", "Inserisci almeno un dato per iniziare la ricerca!");
    cercaPiatto::accept();
}
void cercaPiatto::buttonChiusura(){
    cercaPiatto::reject();
}


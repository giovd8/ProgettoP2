#include "inserimentopiatto.h"

inserimentoPiatto::inserimentoPiatto(modello* mm, QWidget* d):
    QDialog(d),
    selectB(new QLabel("Seleziona il tipo di piatto che vuoi aggiungere:",this)),
    //bottoni selezione inserimento
    primiB(new QPushButton("Inserisci primo",this)),
    secondiB(new QPushButton("Inserisci secondo",this)),
    contorniB(new QPushButton("Inserisci contorno",this)),
    //piatto base
    nomeP(new QLabel("Nome:",this)),
    veganoP(new QLabel("Vegano:",this)),
    glutenFreeP(new QLabel("GlutenFree:",this)),
    prezzoBaseP(new QLabel("Modifica prezzo base:",this)),
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
    //pulsante carica immagine
    caricaImmagine(new QPushButton("Carica immagine",this)),
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
    selectB->setAlignment(Qt::AlignCenter);
    selectB->setStyleSheet("QLabel { font: 15px; }");
    mainView->addWidget(selectB,0,0,1,1);

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

    //inserisco pulsante carica immagine
    QHBoxLayout* w=new QHBoxLayout;
    w->addWidget(caricaImmagine);
    mainView->addLayout(w,4,0,1,1);

    //inserisco pulsanti aggiungi/chiudi
    QHBoxLayout* q=new QHBoxLayout;
    q->addWidget(aggiungiP);
    q->addWidget(close);
    mainView->addLayout(q,5,0,1,1);

    primiView->show();
    secondiView->hide();
    contorniView->hide();

    aggiungiP->setDefault(true);

    //connect pulsanti
    connect(primiB,SIGNAL(clicked()),this,SLOT(buttonAggiungiPrimi()));
    connect(secondiB,SIGNAL(clicked()),this,SLOT(buttonAggiungiSecondi()));
    connect(contorniB,SIGNAL(clicked()),this,SLOT(buttonAggiungiContorni()));
    connect(caricaImmagine,SIGNAL(clicked()),this,SLOT(buttonCaricaImmagine()));
    connect(aggiungiP,SIGNAL(clicked()),this,SLOT(buttonAggiungiP()));
    connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));

    setLayout(mainView);
}

void inserimentoPiatto::buttonAggiungiPrimi(){
    primiView->show();
    secondiView->hide();
    contorniView->hide();
    this->adjustSize();
}

void inserimentoPiatto::buttonAggiungiSecondi(){
    primiView->hide();
    secondiView->show();
    contorniView->hide();
    this->adjustSize();
}

void inserimentoPiatto::buttonAggiungiContorni(){
    primiView->hide();
    secondiView->hide();
    contorniView->show();
    this->adjustSize();
}

piattoBase* inserimentoPiatto::insertNuovoPiatto(){
    //dati base da verificare in caso di inserimento doppio
    string nomeNewP=(insertNomeP->text()).toLocal8Bit().constData();
    string tipoCarnePesceNewP=(insertTipoCarnePesceP->text()).toLocal8Bit().constData();
    string tipoContornoNewP=(insertTipoContornoP->text()).toLocal8Bit().constData();
    container<piattoBase*>::iteratore it=m->mBegin();
    bool esistente=false;
    for(; it!=m->mEnd() && !esistente; ++it) {
        if(nomeNewP==(*it)->getNome()) {
            primo* p=dynamic_cast<primo*>(*it);
            secondo* s=dynamic_cast<secondo*>(*it);
            contorno* c=dynamic_cast<contorno*>(*it);
            if(p || (s && s->getTipoCarnePesce()==tipoCarnePesceNewP) || (c && c->getTipoContorno()==tipoContornoNewP)) {
                esistente=true;
                QMessageBox::warning(this,"Inserimento non riuscito", "ERRORE: Piatto già esistente!");
                return nullptr;
            }
        }
    }
    bool veganoNewP=false;
    bool glutenFreeNewP=false;
    string prezzoTemp=(insertPrezzoBaseP->text()).toLocal8Bit().constData();
    if (insertVeganoP->isChecked())
        veganoNewP=true;
    if (insertGlutenFreeP->isChecked())
        glutenFreeNewP=true;
    double prezzoBaseNewP = atof(prezzoTemp.c_str());
    string urlImmNewP=urlImmagine.toStdString();
    if(urlImmNewP=="")
        urlImmNewP=":/piattiMenu/immagini/vuota.png";
    //primo
    if(primiView->isVisible()){
        if(prezzoBaseNewP==0)
            prezzoBaseNewP=5;
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
            return new primo(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,urlImmNewP,soiaNewP,tipoPastaNewP,condimentoNewP,ingrediente1NewP,ingrediente2NewP,ingrediente3NewP);
    }
    //secondo
    else if(secondiView->isVisible()) {
        if(prezzoBaseNewP==0)
            prezzoBaseNewP=7;
        string tipoPiattoNewP=(insertTipoPiattoP->text()).toLocal8Bit().constData();
        if(nomeNewP=="" || tipoCarnePesceNewP=="" || tipoPiattoNewP=="")
            QMessageBox::warning(this,"Inserimento non riuscito", "ERRORE: Nome, tipo carne/pesce e tipo di cottura sono necessari!");
        else
            return new secondo(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,urlImmNewP,tipoCarnePesceNewP,tipoPiattoNewP);
    }
    //contorno
    else if(contorniView->isVisible()) {
        if(prezzoBaseNewP==0)
            prezzoBaseNewP=3;
        if(nomeNewP=="" || tipoContornoNewP=="")
            QMessageBox::warning(this,"Inserimento non riuscito", "ERRORE: Nome e tipo di contorno sono necessari!");
        else
            return new contorno(nomeNewP,veganoNewP,glutenFreeNewP,prezzoBaseNewP,urlImmNewP,tipoContornoNewP);
    }
    return nullptr;
}

void inserimentoPiatto::buttonCaricaImmagine(){
    urlImmagine = QFileDialog::getOpenFileName(this, tr("Scegli File"), ":/piattiMenu", "File immagine(*.JPG;*.PNG;*.JPEG)");
//    m->nuovoPercorso(urlImmagine.toStdString());
//    m->caricamentoDati();
    caricaImmagine->setIcon(QIcon(urlImmagine));
    caricaImmagine->setIconSize(QSize(200,200));
}


void inserimentoPiatto::buttonAggiungiP(){
    piattoBase* temp=insertNuovoPiatto();
    if(temp!=nullptr) {
        m->getLista()->pushEnd(temp);
        QMessageBox::information(this, "Inserimento completato", "Il nuovo piatto è stato aggiuto correttamente alla lista!");
        m->setSalvataggioEffetuato(false);
        //m->salvataggioDati();
        inserimentoPiatto::accept();
    }
}
void inserimentoPiatto::buttonChiusura(){
   inserimentoPiatto::reject();
}


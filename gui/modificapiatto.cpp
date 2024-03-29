#include "modificapiatto.h"

modificaPiatto::modificaPiatto(modello* mm, piattoBase* pMod, QWidget* d):
    QDialog(d),
    //piatto base
    nomeP(new QLabel("Nome:",this)),
    veganoP(new QLabel("Vegano:",this)),
    glutenFreeP(new QLabel("GlutenFree:",this)),
    prezzoBaseP(new QLabel("Modifica prezzo base:",this)),
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
    tipoCarnePesceP(new QLabel("Tipo di carne o pesce:",this)),
    tipoPiattoP(new QLabel("Tipo cottura:",this)),
    modificaTipoCarnePesceP(new QLineEdit(this)),
    modificaTipoPiattoP(new QLineEdit(this)),
    //contorni
    tipoContornoP(new QLabel("Tipologia contorno:",this)),
    modificaTipoContornoP(new QLineEdit(this)),
    //view dinamiche
    primiView(new QWidget(this)),
    secondiView(new QWidget(this)),
    contorniView(new QWidget(this)),
    //pulsante carica immagine
    caricaImmagine(new QPushButton("Carica immagine",this)),
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

    //inserisco i widget primo piatto nella sottogriglia
    QGridLayout* listaModificaPrimi = new QGridLayout;
    listaModificaPrimi->addWidget(soiaP,0,0,1,1);
    listaModificaPrimi->addWidget(modificaSoiaP,0,1,1,1);
    listaModificaPrimi->addWidget(tipoPastaP,1,0,1,1);
    listaModificaPrimi->addWidget(modificaTipoPastaP,1,1,1,1);
    listaModificaPrimi->addWidget(condimentoP,2,0,1,1);
    listaModificaPrimi->addWidget(modificaCondimentoP,2,1,1,1);
    listaModificaPrimi->addWidget(ingrediente1P,3,0,1,1);
    listaModificaPrimi->addWidget(modificaIngrediente1P,3,1,1,1);
    listaModificaPrimi->addWidget(ingrediente2P,4,0,1,1);
    listaModificaPrimi->addWidget(modificaIngrediente2P,4,1,1,1);
    listaModificaPrimi->addWidget(ingrediente3P,5,0,1,1);
    listaModificaPrimi->addWidget(modificaIngrediente3P,5,1,1,1);
    primiView->setLayout(listaModificaPrimi);
    mainView->addWidget(primiView,2,0,1,1);

    //inserisco i widget secondo piatto nella sottogriglia
    QGridLayout* listaModificaSecondi = new QGridLayout;
    listaModificaSecondi->addWidget(tipoCarnePesceP,0,0,1,1);
    listaModificaSecondi->addWidget(modificaTipoCarnePesceP,0,1,1,1);
    listaModificaSecondi->addWidget(tipoPiattoP,1,0,1,1);
    listaModificaSecondi->addWidget(modificaTipoPiattoP,1,1,1,1);
    secondiView->setLayout(listaModificaSecondi);
    mainView->addWidget(secondiView,2,0,1,1);

    //inserisco i widget contorno nella sottogriglia
    QGridLayout* listaModificaContorni = new QGridLayout;
    listaModificaContorni->addWidget(tipoContornoP,0,0,1,1);
    listaModificaContorni->addWidget(modificaTipoContornoP,0,1,1,1);
    contorniView->setLayout(listaModificaContorni);
    mainView->addWidget(contorniView,2,0,1,1);

    //setto i qlineedit in base al tipo di piatto che sto modificando
    primo* x=dynamic_cast<primo*>(pMod);
    secondo* y=dynamic_cast<secondo*>(pMod);
    contorno* z=dynamic_cast<contorno*>(pMod);
    if(x) {
        if(x->isSoia())
            modificaSoiaP->setCheckState(Qt::CheckState(true));
        else
            modificaSoiaP->setCheckState(Qt::CheckState(false));
        modificaTipoPastaP->setText(QString::fromStdString(x->getPasta()));
        modificaCondimentoP->setText(QString::fromStdString(x->getCondimento()));
        modificaIngrediente1P->setText(QString::fromStdString(x->getIngrediente1()));
        modificaIngrediente2P->setText(QString::fromStdString(x->getIngrediente2()));
        modificaIngrediente3P->setText(QString::fromStdString(x->getIngrediente3()));
        primiView->show();
        secondiView->hide();
        contorniView->hide();
    }
    else if(y){
        modificaTipoCarnePesceP->setText(QString::fromStdString(y->getTipoCarnePesce()));
        modificaTipoPiattoP->setText(QString::fromStdString(y->getTipoPiatto()));
        primiView->hide();
        secondiView->show();
        contorniView->hide();
    }
    else    if(z){
        modificaTipoContornoP->setText(QString::fromStdString(z->getTipoContorno()));
        primiView->hide();
        secondiView->hide();
        contorniView->show();
    }

    //inserisco pulsante carica immagine
    QHBoxLayout* w=new QHBoxLayout;
    w->addWidget(caricaImmagine);
    mainView->addLayout(w,3,0,1,1);

    //inserisco pulsanti Modifica/chiudi
    QHBoxLayout* q=new QHBoxLayout;
    q->addWidget(modificaP);
    q->addWidget(close);
    mainView->addLayout(q,4,0,1,1);

    modificaP->setDefault(true);
    modificaP->setEnabled(false);

    //connect che abilita il tasto modifica in caso venga camabiato almeno un dato
    connect(modificaNomeP,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaVeganoP,SIGNAL(stateChanged(int)),this,SLOT(showButtonModificaP()));
    connect(modificaGlutenFreeP,SIGNAL(stateChanged(int)),this,SLOT(showButtonModificaP()));
    connect(modificaPrezzoBaseP,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaSoiaP,SIGNAL(stateChanged(int)),this,SLOT(showButtonModificaP()));
    connect(modificaCondimentoP,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaTipoPastaP,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaIngrediente1P,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaIngrediente2P,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaIngrediente3P,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaTipoCarnePesceP,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaTipoPiattoP,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));
    connect(modificaTipoContornoP,SIGNAL(textEdited(QString)),this,SLOT(showButtonModificaP()));

    //connect pulsanti
    connect(caricaImmagine,SIGNAL(clicked()),this,SLOT(buttonCaricaImmagine()));
    connect(modificaP,SIGNAL(clicked()),this,SLOT(buttonModificaP()));
    connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));
    setLayout(mainView);
}

bool modificaPiatto::modificaPiattoCorrente(piattoBase* mod){
    bool esistente=false;
    bool modifica=false;
    //parametri base per verificare se i piatti sono uguali
    string nomeNewP=(modificaNomeP->text()).toLocal8Bit().constData();
    string tipoCarnePesceNewP=(modificaTipoCarnePesceP->text()).toLocal8Bit().constData();
    string tipoContornoNewP=(modificaTipoContornoP->text()).toLocal8Bit().constData();
    if(nomeNewP!=pb->getNome()){
        container<piattoBase*>::iteratore it=m->mBegin();
        for(; it!=m->mEnd() && !esistente; ++it) {
            if(nomeNewP==(*it)->getNome()) {
                primo* p=dynamic_cast<primo*>(*it);
                secondo* s=dynamic_cast<secondo*>(*it);
                contorno* c=dynamic_cast<contorno*>(*it);
                if(p || (s && s->getTipoCarnePesce()==tipoCarnePesceNewP) || (c && c->getTipoContorno()==tipoContornoNewP)) {
                    esistente=true;
                    QMessageBox::warning(this,"Modifica non riuscita", "ERRORE: Piatto già esistente!");
                }
            }
        }
    }
    //se il piatto non esiste gia imposto i nuovi valori
    if(!esistente) {
        //piatto base
        if(nomeNewP!="")
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
        string urlImmNewP=urlImmagine.toStdString();
        if(urlImmNewP!="")
            mod->setUrlImmagine(urlImmNewP);
        //primo
        primo* p=dynamic_cast<primo*>(mod);
        secondo* s=dynamic_cast<secondo*>(mod);
        contorno* c=dynamic_cast<contorno*>(mod);
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
        else if (s){
            string tipoPiattoNewP=(modificaTipoPiattoP->text()).toLocal8Bit().constData();
            if(nomeNewP=="" || tipoCarnePesceNewP=="" || tipoPiattoNewP=="")
                QMessageBox::warning(this,"Modifica non riuscita", "ERRORE: Nome, tipo carne/pesce e tipo di cottura sono necessari!");
             else {
                s->setTipoCarnePesce(tipoCarnePesceNewP);
                s->setTipoPiatto(tipoPiattoNewP);
                modifica=true;
             }
       }
       else if (c){
            if(nomeNewP=="" || tipoContornoNewP=="")
                QMessageBox::warning(this,"Modifica non riuscita", "ERRORE: Tutti i campi, ad eccezione del prezzo base, sono necessari!");
            else {
                c->setTipoContorno(tipoContornoNewP);
                modifica=true;
            }
        }

    }
    //se il piatto esisteva gia rimposto i valori iniziali
    else {
        modificaNomeP->setText(QString::fromStdString(mod->getNome()));
        if(mod->isVegano())
            modificaVeganoP->setCheckState(Qt::CheckState(true));
        else
            modificaVeganoP->setCheckState(Qt::CheckState(false));
        if(mod->isGlutenFree())
            modificaGlutenFreeP->setCheckState(Qt::CheckState(true));
        else
            modificaGlutenFreeP->setCheckState(Qt::CheckState(false));
        modificaPrezzoBaseP->setText(QString::number(mod->getPrezzoBase()));
        primo* x=dynamic_cast<primo*>(mod);
        secondo* y=dynamic_cast<secondo*>(mod);
        contorno* z=dynamic_cast<contorno*>(mod);
        if(x) {
            if(x->isSoia())
                modificaSoiaP->setCheckState(Qt::CheckState(true));
            else
                modificaSoiaP->setCheckState(Qt::CheckState(false));
            modificaTipoPastaP->setText(QString::fromStdString(x->getPasta()));
            modificaCondimentoP->setText(QString::fromStdString(x->getCondimento()));
            modificaIngrediente1P->setText(QString::fromStdString(x->getIngrediente1()));
            modificaIngrediente2P->setText(QString::fromStdString(x->getIngrediente2()));
            modificaIngrediente3P->setText(QString::fromStdString(x->getIngrediente3()));
        }
        else if(y){
                modificaTipoCarnePesceP->setText(QString::fromStdString(y->getTipoCarnePesce()));
                modificaTipoPiattoP->setText(QString::fromStdString(y->getTipoPiatto()));
        }
        else if(z)
                modificaTipoContornoP->setText(QString::fromStdString(z->getTipoContorno()));
   }
   return modifica;
}

void modificaPiatto::buttonCaricaImmagine(){
    urlImmagine = QFileDialog::getOpenFileName(this, tr("Scegli File"), ":/piattiMenu", "File immagine(*.JPG;*.PNG;*.JPEG)");
    caricaImmagine->setIcon(QIcon(urlImmagine));
    string isNewURL=urlImmagine.toStdString();
    if(isNewURL!=pb->getUrlImmagine())
        showButtonModificaP();
}

void modificaPiatto::buttonModificaP(){
    bool modifica=modificaPiatto::modificaPiattoCorrente(pb);
    if(modifica) {
        m->setSalvataggioEffetuato(false);
        QMessageBox::information(this, "Modifica completata", "Il piatto è stato modificato correttamente!");
        modificaPiatto::accept();
    }
}

void modificaPiatto::showButtonModificaP(){
    modificaP->setEnabled(true);
}

void modificaPiatto::buttonChiusura(){
   modificaPiatto::reject();
}

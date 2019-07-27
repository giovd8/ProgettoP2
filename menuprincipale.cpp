#include"menuprincipale.h"


menuprincipale::menuprincipale(QWidget* p, bool s):
    QWidget(p),
    salva(new QPushButton("Salva", this)),
    close(new QPushButton("Chiudi", this)),
    salvataggioEffetuato(s)
{
    QHBoxLayout* x=new QHBoxLayout;
    x->addWidget(salva);
    x->addWidget(close);

    //Connect pulsanti: il bottone salva lo gestisco sul modello
    //connect(salva,SIGNAL(clicked()),this,SLOT(buttonSalvataggio()));
    connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));

    setLayout(x);
}

void menuprincipale::buttonSalvataggio(){
    QApplication::quit();
}

void menuprincipale::buttonChiusura() {
    if(salvataggioEffetuato==false)
        QMessageBox::warning(this,"Attenzione", "modifiche menu non salvate");
    QApplication::quit();
}

QPushButton* menuprincipale::getSalvaB() const {
    return salva;
}

void menuprincipale::setSalvataggio(bool s) {
    salvataggioEffetuato=s;
}

//QPushButton* menuprincipale::getClose(){
//    return close;
//}

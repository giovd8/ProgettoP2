#include"menuprincipale.h"


menuprincipale::menuprincipale(QWidget* p):
    QWidget(p),
    salva(new QPushButton("Salva", this)),
    close(new QPushButton("Chiudi", this))
    //salvataggioEffetuato(s)
{
    QHBoxLayout* x=new QHBoxLayout;
//    const QSize btnSize = QSize(100, 40);
//    salva->setFixedSize(btnSize);
//    close->setFixedSize(btnSize);
    x->addWidget(salva);
    x->addWidget(close);




    //Connect pulsanti: il bottone salva lo gestisco sul modello
    //connect(salva,SIGNAL(clicked()),this,SLOT(buttonSalvataggio()));
    //connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));

    setLayout(x);
}

//void menuprincipale::buttonSalvataggio(){
//    QApplication::quit();
//}

//void menuprincipale::buttonChiusura() {
//    if(salvataggioEffetuato==false)
//        QMessageBox::warning(this,"Attenzione", "modifiche menu non salvate");
//    QApplication::quit();
//}

QPushButton* menuprincipale::getSalva() const {
    return salva;
}

QPushButton* menuprincipale::getClose() const {
    return close;
}

//void menuprincipale::setSalvataggio(bool s) {
//    salvataggioEffetuato=s;
//}


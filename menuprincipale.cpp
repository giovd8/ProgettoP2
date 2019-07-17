#include"menuprincipale.h"


menuprincipale::menuprincipale(QWidget* p):
    QWidget(p),
    salva(new QPushButton("Salva", this)),
    close(new QPushButton("Close", this))
{
    QVBoxLayout* x=new QVBoxLayout;
    x->addWidget(salva);
    x->addWidget(close);

    //Connect pulsanti
    connect(close,SIGNAL(clicked()),this,SLOT(buttonChiusura()));




    setLayout(x);
}

void menuprincipale::buttonChiusura(){
    QApplication::quit();
}

//QPushButton* menuprincipale::getClose(){
//    return close;
//}

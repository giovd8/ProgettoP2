#include"menuprincipale.h"


menuprincipale::menuprincipale(QWidget* p):
    QWidget(p),
    salva(new QPushButton("Salva", this)),
    close(new QPushButton("Chiudi", this))
{
    QHBoxLayout* x=new QHBoxLayout;
    x->addWidget(salva);
    x->addWidget(close);

    setLayout(x);
}

QPushButton* menuprincipale::getSalva() const {
    return salva;
}

QPushButton* menuprincipale::getClose() const {
    return close;
}


#include "modifichedati.h"

modifichedati::modifichedati(QWidget* p):
    QWidget(p),
    aggiungi(new QPushButton("Aggiungi", this)),
    modifica(new QPushButton("Modifica", this)),
    elimina(new QPushButton("Elimina",this)),
    cerca(new QPushButton("Cerca",this))
{
    QHBoxLayout* x=new QHBoxLayout;
    x->addWidget(aggiungi);
    x->addWidget(modifica);
    x->addWidget(elimina);
    x->addWidget(cerca);
    setLayout(x);
}

QPushButton* modifichedati::getAggiungiPiatto() const {
    return aggiungi;
}

QPushButton* modifichedati::getModificaPiatto() const {
    return modifica;
}

QPushButton* modifichedati::getEliminaPiatto() const {
    return elimina;
}

QPushButton* modifichedati::getCercaPiatto() const {
    return cerca;
}


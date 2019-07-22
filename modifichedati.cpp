#include "modifichedati.h"

modifichedati::modifichedati(QWidget* p):
    QWidget(p),
    aggiungi(new QPushButton("Aggiungi", this)),
    modifica(new QPushButton("modifica", this)),
    elimina(new QPushButton("Elimina",this))
{
    QHBoxLayout* x=new QHBoxLayout;
    x->addWidget(aggiungi);
    x->addWidget(modifica);
    x->addWidget(elimina);

    setLayout(x);
}

QPushButton* modifichedati::getAggiungiPiatto() const {
    return aggiungi;
}

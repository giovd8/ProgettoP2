#include "viewpiatti.h"

viewprodotti::viewprodotti(QWidget* p):
    QWidget(p),
    tuttiPiatti(new QPushButton("Tutti i piatti",this)),
    tuttiPrimi(new QPushButton("Primi piatti",this)),
    tuttiSecondi(new QPushButton("Secondi piatti",this)),
    tuttiContorni(new QPushButton("Contorni",this)),
    lista(new QListWidget())
{
    QHBoxLayout* y=new QHBoxLayout;
    y->addWidget(tuttiPiatti);
    y->addWidget(tuttiPrimi);
    y->addWidget(tuttiSecondi);
    y->addWidget(tuttiContorni);

    QHBoxLayout* z=new QHBoxLayout;
    z->addWidget(lista);

    QVBoxLayout* x=new QVBoxLayout;
    x->addLayout(y);
    x->addLayout(z);

    setLayout(x);
}


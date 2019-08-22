#include"viewpiatti.h"

viewpiatti::viewpiatti(QWidget* p):
    QWidget(p),
    tuttiPiatti(new QPushButton("Tutti i piatti",this)),
    tuttiPrimi(new QPushButton("Primi piatti",this)),
    tuttiSecondi(new QPushButton("Secondi piatti",this)),
    tuttiContorni(new QPushButton("Contorni",this)),
    lista(new listaPContainer(this))
{
    QHBoxLayout* y=new QHBoxLayout;
    y->addWidget(tuttiPiatti);
    y->addWidget(tuttiPrimi);
    y->addWidget(tuttiSecondi);
    y->addWidget(tuttiContorni);

    QHBoxLayout* z=new QHBoxLayout;
    z->addWidget(lista);
    lista->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout* x=new QVBoxLayout;
    x->addLayout(y);
    x->addLayout(z);

    setLayout(x);
}

QPushButton* viewpiatti::getTuttiPiatti() const {
    return tuttiPiatti;
}

QPushButton* viewpiatti::getTuttiPrimi() const {
    return tuttiPrimi;
}

QPushButton* viewpiatti::getTuttiSecondi() const {
    return tuttiSecondi;
}

QPushButton* viewpiatti::getTuttiContorni() const {
    return tuttiContorni;
}
listaPContainer* viewpiatti::getLista() const {
    return lista;
}


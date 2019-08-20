#include "listapcontainer.h"

//Costruttore
listaPContainer::listaPContainer(QWidget* p) : parent(p) {
    setIconSize(QSize(200,200));
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);
    //addScrollBarWidget(new QScrollBar(parent),Qt::AlignRight);
}

//"Trasforma" il piatto in un elemento della mia lista
void listaPContainer::aggiungiPiatto(piattoBase* pt){
    elementiListaP* piatto = new elementiListaP(parent, pt);
    addItem(piatto);
}

//Piatto corrente della mia lista
elementiListaP * listaPContainer::piattoCorrente() const{
    return static_cast<elementiListaP*>(QListWidget::currentItem());
}



#include "listapcontainer.h"

//Costruttore
listaPContainer::listaPContainer(QWidget* p) :
    parent(p)
{
    addScrollBarWidget(new QScrollBar(parent),Qt::AlignRight);
}

//"Trasforma" il piatto in un elemento della mia lista
void listaPContainer::aggiungiPiatto(piattoBase* pt){
    elementiListaP* piatto = new elementiListaP(parent, pt);
    addItem(piatto);
}

//Piuatto corrente della mia lista
elementiListaP * listaPContainer::piattoCorrente() const{
    return static_cast<elementiListaP*>(QListWidget::currentItem());
}

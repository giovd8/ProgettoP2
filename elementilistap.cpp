#include "elementilistap.h"

elementiListaP::elementiListaP(QWidget* p, piattoBase* pt):
    parent(p),
    piatto(pt)
{
   aggiungi();
}

piattoBase* elementiListaP::prelevaPiatto() const {
    if(piatto)
        return piatto;
    else
        return nullptr;
}

void elementiListaP::aggiungi() {
    setText(QString::fromStdString(piatto->piattoInString(piatto)));
}


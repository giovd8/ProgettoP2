#include "elementilistap.h"

elementiListaP::elementiListaP(QWidget* p, piattoBase* pt) : parent(p), piatto(pt) {
   aggiungi();
}

piattoBase* elementiListaP::prelevaPiatto() const {
    if(piatto)
        return piatto;
    else
        return nullptr;
}

void elementiListaP::aggiungi() {
    //aggiungo immagine alla lista
    QPixmap p(QString::fromStdString(piatto->getUrlImmagine()));
    setIcon(p.scaled(200,200,Qt::AspectRatioMode::KeepAspectRatio));
    //aggiungo testo alla lista
    setText(QString::fromStdString(piatto->piattoInString(piatto)));
}


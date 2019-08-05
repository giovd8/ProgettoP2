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

//    QString urlImg = QString::fromStdString(piatto->getUrlImmagine());
//    std::cout << urlImg.toStdString() << std::endl;

    QString urlImg = QString::fromStdString(piatto->getUrlImmagine());
    std::cout << urlImg.toStdString() << std::endl;
    QPixmap p(urlImg);
    setIcon(p.scaled(200,200,Qt::AspectRatioMode::KeepAspectRatio)); //Per l'immagine

    setText(QString::fromStdString(piatto->piattoInString(piatto)));
}


#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QApplication>
#include <QWidget>
#include"menuprincipale.h"
#include"modifichedati.h"
#include"viewpiatti.h"
#include"modello.h"
#include"inserimentopiatto.h"


class controller: public QWidget {
    friend class inserimentoPiatto;
     Q_OBJECT
private:
    QString xmlFile;
    modello* m;
    menuprincipale* mp;
    modifichedati* md;
    viewpiatti* viewP;
    inserimentoPiatto* ip;

public slots:
    void caricaPiatti() const;
    void caricaPrimi() const;
    void caricaSecondi() const;
    void caricaContorni() const;
    void aggiungiPiatto();



public:
    controller(QWidget * parent= nullptr);
    void aggiungiPiattoContainer();

};

#endif // CONTROLLER_H

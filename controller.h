#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QApplication>
#include <QWidget>
#include"menuprincipale.h"
#include"modifichedati.h"
#include"viewpiatti.h"
#include"modello.h"
#include"inserimentopiatto.h"
#include"modificapiatto.h"
#include"cercapiatto.h"
//#include"listapcontainer.h"



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
    void salvaModello();
    void caricaPiatti() const;
    void caricaPrimi() const;
    void caricaSecondi() const;
    void caricaContorni() const;
    //void caricaRisultatiRicerca() const;
    void aggiungiPiatto();
    void modPiatto();
    void eliminaPiatto();
    void findPiatto();
    void gestisciPulsantiModElim() const;

public:
    controller(QWidget * parent= nullptr);

};

#endif // CONTROLLER_H

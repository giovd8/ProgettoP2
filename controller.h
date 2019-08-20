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
    void closeApp() ;
    void caricaPiatti() const;
    void caricaPrimi() const;
    void caricaSecondi() const;
    void caricaContorni() const;
    void aggiungiPiatto();
    void modPiatto();
    void eliminaPiatto();
    void findPiatto();
    void gestisciPulsantiModElim() const;

public:
    controller(QWidget * parent= nullptr);
    void closeEvent(QCloseEvent *event) override;

};

#endif // CONTROLLER_H

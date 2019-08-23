#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<QApplication>
#include<QWidget>
#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QtWidgets>
#include<QDebug>
#include<QLabel>

#include"gui/menuprincipale.h"
#include"gui/modifichedati.h"
#include"gui/viewpiatti.h"
#include"modello.h"
#include"gui/inserimentopiatto.h"
#include"gui/modificapiatto.h"
#include"gui/cercapiatto.h"

class controller: public QWidget {
     Q_OBJECT
private:
    QString xmlFile;
    modello* m;
    menuprincipale* mp;
    modifichedati* md;
    viewpiatti* viewP;

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

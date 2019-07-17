#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QApplication>
#include <QWidget>
#include"menuprincipale.h"
#include"modifichedati.h"
#include"viewpiatti.h"
#include"modello.h"


class controller: public QWidget {
     Q_OBJECT
private:
    QString xmlFile;
    modello* m;
    //listaPiatti* lp;
    menuprincipale* mp;
    modifichedati* md;
    viewprodotti* vp;
public slots:
    //void caricaPiatti();

public:
    controller(QWidget * parent= nullptr);
};

#endif // CONTROLLER_H

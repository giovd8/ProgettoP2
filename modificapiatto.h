#ifndef MODIFICAPIATTO_H
#define MODIFICAPIATTO_H

#include<QDialog>
#include<QHBoxLayout>
#include<QPushButton>
#include<QApplication>
#include<QLabel>
#include<QLineEdit>
#include<QCheckBox>
#include<QWidget>
#include<iostream>
#include <QMessageBox>
using namespace std;

#include"piattobase.h"
#include"primo.h"
#include"secondo.h"
#include"contorno.h"
#include"modello.h"


class modificaPiatto: public QDialog {
    friend class controller;
    Q_OBJECT
    private:
        QPushButton* primiB;
        QPushButton* secondiB;
        QPushButton* contorniB;
        //piatto base
        QLabel* nomeP;
        QLabel* veganoP;
        QLabel* glutenFreeP;
        QLabel* prezzoBaseP;
        QLineEdit* modificaNomeP;
        QCheckBox* modificaVeganoP;
        QCheckBox* modificaGlutenFreeP;
        QLineEdit* modificaPrezzoBaseP;
        //primo piatto
        QLabel* soiaP;
        QLabel* tipoPastaP;
        QLabel* ingrediente1P;
        QLabel* ingrediente2P;
        QLabel* ingrediente3P;
        QLabel* ingrediente4P;
        QCheckBox* modificaSoiaP;
        QLineEdit* modificaTipoPastaP;
        QLineEdit* modificaIngrediente1P;
        QLineEdit* modificaIngrediente2P;
        QLineEdit* modificaIngrediente3P;
        QLineEdit* modificaIngrediente4P;
        //secondi piatto
        QLabel* tipoCarneP;
        QLabel* tipoPesceP;
        QLabel* tipoPiattoP;
        QLabel* tipoCotturaP;
        QLineEdit* modificaTipoCarneP;
        QLineEdit* modificaTipoPesceP;
        QLineEdit* modificaTipoPiattoP;
        QLineEdit* modificaTipoCotturaP;
        //contorno
        QLabel* tipoNomeContornoP;
        QLabel* tipoContornoP;
        QLineEdit* modificaTipoNomeContornoP;
        QLineEdit* modificaTipoContornoP;
        //contenitori view
        QWidget *primiView;
        QWidget *secondiView;
        QWidget *contorniView;
        //Modifica/chiudi
        QPushButton* ModificaP;
        QPushButton* close;

        modello* m;

    public slots:
        void buttonModificaPrimi();
        void buttonModificaSecondi();
        void buttonModificaContorni();
        void buttonModificaP();
        void buttonChiusura();
        //void disablePesce();
    public:
        modificaPiatto(modello*m, QWidget* parent);
        piattoBase* modificaNuovoPiatto();
};

#endif // MODIFICAPIATTO_H

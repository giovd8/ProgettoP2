#ifndef INSERIMENTOPIATTO_H
#define INSERIMENTOPIATTO_H
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


class inserimentoPiatto: public QDialog {
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
        QLineEdit* insertNomeP;
        QCheckBox* insertVeganoP;
        QCheckBox* insertGlutenFreeP;
        QLineEdit* insertPrezzoBaseP;
        //primo piatto
        QLabel* soiaP;
        QLabel* tipoPastaP;
        QLabel* ingrediente1P;
        QLabel* ingrediente2P;
        QLabel* ingrediente3P;
        QLabel* ingrediente4P;
        QCheckBox* insertSoiaP;
        QLineEdit* insertTipoPastaP;
        QLineEdit* insertIngrediente1P;
        QLineEdit* insertIngrediente2P;
        QLineEdit* insertIngrediente3P;
        QLineEdit* insertIngrediente4P;
        //secondi piatto
        QLabel* tipoCarneP;
        QLabel* tipoPesceP;
        QLabel* tipoPiattoP;
        QLabel* tipoCotturaP;
        QLineEdit* insertTipoCarneP;
        QLineEdit* insertTipoPesceP;
        QLineEdit* insertTipoPiattoP;
        QLineEdit* insertTipoCotturaP;
        //contorno
        QLabel* tipoNomeContornoP;
        QLabel* tipoContornoP;
        QLineEdit* insertTipoNomeContornoP;
        QLineEdit* insertTipoContornoP;
        //contenitori view
        QWidget *primiView;
        QWidget *secondiView;
        QWidget *contorniView;
        //aggiungi/chiudi
        QPushButton* aggiungiP;
        QPushButton* close;

        modello* m;

    public slots:
        void buttonAggiungiPrimi();
        void buttonAggiungiSecondi();
        void buttonAggiungiContorni();
        void buttonAggiungiP();
        void buttonChiusura();
        //void disablePesce();
    public:
        inserimentoPiatto(modello*m, QWidget* parent);
        piattoBase* insertNuovoPiatto();
};

#endif // INSERIMENTOPIATTO_H

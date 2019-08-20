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
#include<QFileDialog>
#include<iostream>
#include <QMessageBox>
using namespace std;

#include"piattobase.h"
#include"primo.h"
#include"secondo.h"
#include"contorno.h"
#include"modello.h"


class modificaPiatto: public QDialog {
    Q_OBJECT
    private:
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
        QLabel* condimentoP;
        QLabel* ingrediente1P;
        QLabel* ingrediente2P;
        QLabel* ingrediente3P;
        QCheckBox* modificaSoiaP;
        QLineEdit* modificaTipoPastaP;
        QLineEdit* modificaCondimentoP;
        QLineEdit* modificaIngrediente1P;
        QLineEdit* modificaIngrediente2P;
        QLineEdit* modificaIngrediente3P;
        //secondi piatto
        QLabel* tipoCarnePesceP;
        QLabel* tipoPiattoP;
        QLineEdit* modificaTipoCarnePesceP;
        QLineEdit* modificaTipoPiattoP;
        //contorno
        QLabel* tipoContornoP;
        QLineEdit* modificaTipoContornoP;
        //contenitori view
        QWidget *primiView;
        QWidget *secondiView;
        QWidget *contorniView;
        //carica immagine
        QPushButton* caricaImmagine;
        //aggiungi/chiudi
        QPushButton* modificaP;
        QPushButton* close;
        //url immagine
        QString urlImmagine;
        //modello
        modello* m;
        //piatto da modificare
        piattoBase* pb;
    public slots:
        void buttonCaricaImmagine();
        void buttonModificaP();
        void showButtonModificaP();
        void buttonChiusura();
    public:
        modificaPiatto(modello*m, piattoBase* pb, QWidget* parent);
        bool modificaPiattoCorrente(piattoBase*);
};

#endif // MODIFICAPIATTO_H

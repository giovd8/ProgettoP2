#ifndef CERCAPIATTO_H
#define CERCAPIATTO_H
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QCheckBox>
#include<QPushButton>
#include<QGridLayout>
#include<QMessageBox>
#include<QApplication>
#include<QWidget>
#include<QHBoxLayout>

#include"piattobase.h"
#include"primo.h"
#include"secondo.h"
#include"contorno.h"
#include"modello.h"

class cercaPiatto: public QDialog {
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
        QPushButton* cercaP;
        QPushButton* close;
        //modello
        modello* m;
    public slots:
        void buttonCercaPrimi();
        void buttonCercaSecondi();
        void buttonCercaContorni();
        void buttonCercaP();
        void buttonChiusura();
    public:
        cercaPiatto(modello*m, QWidget* parent);
        piattoBase* creaPiattoTemp();
        void cercaPiattoTemp() const;
    };

#endif // CERCAPIATTO_H

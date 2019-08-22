#ifndef CERCAPIATTO_H
#define CERCAPIATTO_H
//#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QCheckBox>
#include<QPushButton>
#include<QGridLayout>
#include<QMessageBox>
#include<QApplication>
#include<QWidget>
#include<QHBoxLayout>

#include"gerarchia/piattobase.h"
#include"gerarchia/primo.h"
#include"gerarchia/secondo.h"
#include"gerarchia/contorno.h"
#include"modello.h"
#include"gui/viewpiatti.h"

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
        QLabel* condimentoP;
        QLabel* ingrediente1P;
        QLabel* ingrediente2P;
        QLabel* ingrediente3P;
        QCheckBox* insertSoiaP;
        QLineEdit* insertTipoPastaP;
        QLineEdit* insertCondimentoP;
        QLineEdit* insertIngrediente1P;
        QLineEdit* insertIngrediente2P;
        QLineEdit* insertIngrediente3P;
        //secondi piatto
        QLabel* tipoCarnePesceP;
        QLabel* tipoPiattoP;
        QLineEdit* insertTipoCarnePesceP;
        QLineEdit* insertTipoPiattoP;
        //contorno
        QLabel* tipoContornoP;
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
        viewpiatti* vp;
    public slots:
        void buttonCercaPrimi();
        void buttonCercaSecondi();
        void buttonCercaContorni();
        void buttonCercaP();
        void buttonChiusura();
    public:
        cercaPiatto(modello*m, viewpiatti* y, QWidget* parent);
        piattoBase* creaPiattoTemp();
        //int cercaInLista(piattoBase*);
        void cercaPiattoTemp() const;
        QPushButton* getCercaP() const;
    };

#endif // CERCAPIATTO_H

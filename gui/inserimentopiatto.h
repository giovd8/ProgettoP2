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
#include<QFileDialog>
#include<QMessageBox>

#include"gerarchia/piattobase.h"
#include"gerarchia/primo.h"
#include"gerarchia/secondo.h"
#include"gerarchia/contorno.h"
#include"modello.h"


class inserimentoPiatto: public QDialog {
    Q_OBJECT
    private:
        QLabel* selectB;
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
        //carica immagine
        QPushButton* caricaImmagine;
        //aggiungi/chiudi
        QPushButton* aggiungiP;
        QPushButton* close;
        //url immagine
        QString urlImmagine;
        //modello
        modello* m;

    public slots:
        void buttonAggiungiPrimi();
        void buttonAggiungiSecondi();
        void buttonAggiungiContorni();
        void buttonCaricaImmagine();
        void buttonAggiungiP();
        void buttonChiusura();
    public:
        inserimentoPiatto(modello*m, QWidget* parent);
        piattoBase* insertNuovoPiatto();
};

#endif // INSERIMENTOPIATTO_H

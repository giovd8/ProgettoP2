#ifndef MENUPRINCIPALE_H
#define MENUPRINCIPALE_H

#include<QPushButton>
#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QApplication>
#include<QListWidget>
#include <QMessageBox>
#include"modello.h"

class menuprincipale: public QWidget {
    Q_OBJECT
    private:
        QPushButton* salva;
        QPushButton* close;
        bool salvataggioEffetuato;
    public slots:
        void buttonSalvataggio();
        void buttonChiusura();
    public:
        menuprincipale(QWidget* =nullptr, bool=true);
        QPushButton* getSalvaB() const;
        void setSalvataggio(bool b);

//        QPushButton* getClose();
};
#endif // MENUPRINCIPALE_H

#ifndef MODIFICHEDATI_H
#define MODIFICHEDATI_H

#include<QPushButton>
#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QApplication>
#include<QListWidget>
#include<QDialog>


class modifichedati: public QWidget {
    Q_OBJECT
    private:
        QPushButton* aggiungi;
        QPushButton* modifica;
        QPushButton* elimina;
    public:
        modifichedati(QWidget* parent);
        QPushButton *getAggiungiPiatto() const;
        QPushButton *getEliminaPiatto() const;
};

#endif // MODIFICHEDATI_H

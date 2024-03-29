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
        QPushButton* cerca;
    public:
        modifichedati(QWidget* parent);
        QPushButton *getAggiungiPiatto() const;
        QPushButton *getModificaPiatto() const;
        QPushButton *getEliminaPiatto() const;
        QPushButton *getCercaPiatto() const;
};

#endif // MODIFICHEDATI_H

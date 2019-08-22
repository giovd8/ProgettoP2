#ifndef VIEWPIATTI_H
#define VIEWPIATTI_H
#include<QPushButton>
#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QApplication>
#include<QListWidget>
#include"gui/listapcontainer.h"
#include"gui/modifichedati.h"

class viewpiatti: public QWidget {
    Q_OBJECT
    private:
        QPushButton* tuttiPiatti;
        QPushButton* tuttiPrimi;
        QPushButton* tuttiSecondi;
        QPushButton* tuttiContorni;
        listaPContainer* lista;
    public:
        viewpiatti(QWidget* parent);
        QPushButton* getTuttiPiatti() const;
        QPushButton* getTuttiPrimi() const;
        QPushButton* getTuttiSecondi() const;
        QPushButton* getTuttiContorni() const;
        listaPContainer* getLista() const;

};

#endif // VIEWPRODOTTI_H

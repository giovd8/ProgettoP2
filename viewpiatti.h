#ifndef VIEWPIATTI_H
#define VIEWPIATTI_H
#include<QPushButton>
#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QApplication>
#include<QListWidget>

class viewprodotti: public QWidget {
    Q_OBJECT
    private:
        QPushButton* tuttiPiatti;
        QPushButton* tuttiPrimi;
        QPushButton* tuttiSecondi;
        QPushButton* tuttiContorni;
        QListWidget* lista;
    public slots:
        //void caricaPiatti();

    public:
        viewprodotti(QWidget* parent);
};

#endif // VIEWPRODOTTI_H

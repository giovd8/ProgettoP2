#ifndef MENUPRINCIPALE_H
#define MENUPRINCIPALE_H

#include<QPushButton>
#include<QLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QApplication>
#include<QListWidget>

class menuprincipale: public QWidget {
    Q_OBJECT
    private:
        QPushButton* salva;
        QPushButton* close;
    public slots:
        void buttonChiusura();
    public:
        menuprincipale(QWidget* parent);

//        QPushButton* getClose();
};
#endif // MENUPRINCIPALE_H

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
    public:
        menuprincipale(QWidget* =nullptr);
        QPushButton* getSalva() const;
        QPushButton* getClose() const;
};
#endif // MENUPRINCIPALE_H

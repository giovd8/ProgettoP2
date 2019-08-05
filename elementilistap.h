#ifndef ELEMENTILISTAP_H
#define ELEMENTILISTAP_H
#include<QListWidgetItem>
#include<QWidget>
#include<QPushButton>
#include"piattobase.h"
#include<QLabel>


class elementiListaP: public QListWidgetItem {
    private:
        QWidget* parent;
        piattoBase* piatto;
        QLabel ql;

    public:
        elementiListaP(QWidget*, piattoBase* =nullptr);
        piattoBase* prelevaPiatto() const;
        void aggiungi();
};

#endif // ELEMENTILISTAP_H

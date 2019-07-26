#ifndef ELEMENTILISTAP_H
#define ELEMENTILISTAP_H
#include<QListWidgetItem>
#include<QWidget>
#include<QPushButton>
#include"piattobase.h"


class elementiListaP: public QListWidgetItem {
    private:
        QWidget* parent;
        piattoBase* piatto;

    public:
        elementiListaP(QWidget*, piattoBase* =nullptr);
        //piattoBase* prelevaPiatto() const;
        void aggiungi();
        piattoBase* prelevaPiatto() const;
};

#endif // ELEMENTILISTAP_H

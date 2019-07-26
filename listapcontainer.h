#ifndef LISTAPCONTAINER_H
#define LISTAPCONTAINER_H

#include<QListWidget>
#include<QScrollBar>
#include<QWidget>
#include"piattobase.h"
#include"elementilistap.h"
#include"modifichedati.h"
#include<iostream>
using namespace std;


class listaPContainer: public QListWidget {
    Q_OBJECT
    private:
        QWidget* parent;
        modifichedati *md;
    public:
        listaPContainer(QWidget* =nullptr);
        void aggiungiPiatto(piattoBase*);
        elementiListaP* piattoCorrente() const;
};

#endif // LISTAPCONTAINER_H

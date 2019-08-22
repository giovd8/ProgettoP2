#ifndef LISTAPCONTAINER_H
#define LISTAPCONTAINER_H

#include<QListWidget>
#include<QScrollBar>
#include<QWidget>
#include<QLabel>
#include"gerarchia/piattobase.h"
#include"gui/elementilistap.h"
#include"gui/modifichedati.h"

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

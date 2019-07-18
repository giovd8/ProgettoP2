#ifndef LISTAPCONTAINER_H
#define LISTAPCONTAINER_H

#include<QListWidget>
#include<QScrollBar>
#include<QWidget>
#include"piattobase.h"
#include"elementilistap.h"


class listaPContainer: public QListWidget {
    Q_OBJECT
    private:
        QWidget* parent;
    public:
    listaPContainer(QWidget* =nullptr);
    void aggiungiPiatto(piattoBase*);
    elementiListaP* piattoCorrente() const;

};

#endif // LISTAPCONTAINER_H

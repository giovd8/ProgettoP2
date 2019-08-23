#ifndef MODELLO_H
#define MODELLO_H

#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>

#include"gerarchia/container.h"
#include"gerarchia/piattobase.h"
#include"gerarchia/primo.h"
#include"gerarchia/secondo.h"
#include"gerarchia/contorno.h"

class modello {
    private:
        container<piattoBase*>*piatti;
        string xmlFile;
        bool salvataggioEffetuato;
    public:
        modello(string, bool=true);
        ~modello();

        bool getSalvataggioEffetuato() const;
        void setSalvataggioEffetuato(bool);

        void nuovoPercorso(string);
        void caricamentoDati() const;
        void salvataggioDati();

        //Funzioni begin e end per modello
        container<piattoBase*>::iteratore mBegin();
        container<piattoBase*>::iteratore mEnd();
        container<piattoBase *>::constIteratore mConstBegin() const;
        container<piattoBase *>::constIteratore mConstEnd() const;
        //Funzione get lista ed elimina oggetto
        container<piattoBase*>*getLista() const;
        void mErase(container<piattoBase*>::iteratore it);
};

#endif // MODELLO_H

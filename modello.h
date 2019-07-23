#ifndef MODELLO_H
#define MODELLO_H
#include"container.h"
#include"piattobase.h"
#include"primo.h"
#include"secondo.h"
#include"contorno.h"
//#include"inserimentopiatto.h"
using std::string;


class modello {
    private:
        container<piattoBase*>* piatti;
        string xmlFile;
        //inserimentoPiatto* insP;
    public:
        modello(string);
        ~modello();

        void caricamentoDati() const;
        void nuovoPercorso(string);
        void caricaOggettoXML();

        //Funzioni begin e end per modello
        container<piattoBase*>::iteratore mBegin();
        container<piattoBase*>::iteratore mEnd();
        //Funzione prendi lista ed elimina oggetto
        container<piattoBase*>*getLista() const;
        void mErase(container<piattoBase*>::iteratore it);
        //container<piattoBase*>::Constiterator mcbegin() const;
        //container<piattoBase*>::Constiterator mcend() const;
};

#endif // MODELLO_H

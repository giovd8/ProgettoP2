#ifndef MODELLO_H
#define MODELLO_H
#include"container.h"
#include"piattobase.h"
#include"primo.h"
#include"secondo.h"
#include"contorno.h"
using std::string;


class modello {
    private:
        container<piattoBase*>* piatti;
        string xmlFile;
    public:
        modello(string);
        ~modello();

        void caricamentoDati() const;
        void setNuovoPercorso(string);

        //Funzioni begin e end per modello
        container<piattoBase*>::iteratore mBegin();
        container<piattoBase*>::iteratore mEnd();

        container<piattoBase*>*getLista() const;
        //container<piattoBase*>::Constiterator mcbegin() const;
        //container<piattoBase*>::Constiterator mcend() const;
};

#endif // MODELLO_H

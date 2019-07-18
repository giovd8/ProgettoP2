#ifndef CONTORNO_H
#define CONTORNO_H
#include "piattobase.h"
#include <string.h>
#include <iostream>
using std::string;


class contorno: public piattoBase {
    private:
        bool patate;
        string tipoContorno;
    public:
        //costruttore contorno
        contorno(string="", bool=true, bool=true, double=3.5, bool=true, string="Inserisci la tipologia di contorno");

        //costruttore di copia
        contorno(const contorno&);

        //metodi GET
        bool getPatate() const;
        string getTipoContorno() const;

        //calcola prezzo finale virtuale
        double prezzoFinale() const;

        //convertire oggetto in stringa
        virtual string piattoInString(piattoBase*) const;

        //overloading operatori
        bool operator==(const piattoBase&) const;
        bool operator!=(const piattoBase&) const;
};

#endif // CONTORNO_H

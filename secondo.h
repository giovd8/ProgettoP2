#ifndef SECONDO_H
#define SECONDO_H
#include "piattobase.h"
#include<string.h>
#include<iostream>
using std::string;

class secondo: public piattoBase {
    private:
        string tipoCarne;
        string tipoPesce;
        string tipoPiatto;
        string tipoCottura;
    public:
        //costruttore secondo
        secondo(string="", bool=false, bool=true, double=10, string="Inserisci il tipo di carne", string="Inserisci il tipo di pesce", string="Inserisci la tipologia del piatto", string="Inserisci il tipo di cottura");

        //costruttore di copia
        secondo(const secondo &);

        //metodi GET
        string getTipoCarne() const;
        string getTipoPesce() const;
        string getTipoPiatto() const;
        string getTipoCottura() const;

        //calcola prezzo finale virtuale
        double prezzoFinale() const;

        //overloading operatori
        bool operator==(const piattoBase&) const;
        bool operator!=(const piattoBase&) const;
};

#endif // SECONDO_H

#ifndef PRIMO_H
#define PRIMO_H
#include "piattobase.h"
#include <string.h>
#include <iostream>
using std::string;

class primo: public piattoBase {
    private:
        bool soia;
        string tipoPasta;
        string ingrediente1;
        string ingrediente2;
        string ingrediente3;
        string ingrediente4;
    public:
        //costruttore primi
        primo(string ="", bool=false, bool=false, double=0, bool=false, string="Inserisci il tipo di pasta", string="Inserisci il primo ingrediente", string="Non hai inserito il secondo ingrediente", string="Non hai inserito il terzo ingrediente", string="Non hai inserito il quarto ingrediente");

        //costruttore di copia
        primo(const primo &);

        //metodi GET
        bool getSoia() const;
        string getPasta() const;
        string getIngrediente1() const;
        string getIngrediente2() const;
        string getIngrediente3() const;
        string getIngrediente4() const;

        //calcola prezzo finale virtuale
        double prezzoFinale() const;

        //overloading operatori
//        bool operator==(const piattoBase&) const;
//        bool operator!=(const piattoBase&) const;

};

#endif // PRIMO_H

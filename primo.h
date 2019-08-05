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
        string condimento;
        string ingrediente1;
        string ingrediente2;
        string ingrediente3;
    public:
        //costruttore primi
        primo(string="", bool=false, bool=false, double=5, string="", bool=false, string="", string="", string="", string="", string="");

        //costruttore di copia
        primo(const primo &);

        //metodi GET
        bool isSoia() const;
        string getPasta() const;
        string getCondimento() const;
        string getIngrediente1() const;
        string getIngrediente2() const;
        string getIngrediente3() const;

        //metodi SET
        void setSoia(bool);
        void setPasta(string);
        void setCondimento(string);
        void setIngrediente1(string);
        void setIngrediente2(string);
        void setIngrediente3(string);

        //calcola prezzo finale virtuale
        double prezzoFinale() const;

        //convertire oggetto in stringa
        string piattoInString(piattoBase*) const;

        //overloading operatori
        bool operator==(const piattoBase&) const;
//        bool operator!=(const piattoBase&) const;

};

#endif // PRIMO_H

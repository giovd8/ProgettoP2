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
        primo(string="", bool=false, bool=false, double=5, bool=false, string="", string="", string="", string="", string="");

        //costruttore di copia
        primo(const primo &);

        //metodi GET
        bool getSoia() const;
        string getPasta() const;
        string getIngrediente1() const;
        string getIngrediente2() const;
        string getIngrediente3() const;
        string getIngrediente4() const;

        //metodi SET
        void setSoia(bool);
        void setPasta(string);
        void setIngrediente1(string);
        void setIngrediente2(string);
        void setIngrediente3(string);
        void setIngrediente4(string);

        //calcola prezzo finale virtuale
        double prezzoFinale() const;

        //convertire oggetto in stringa
        virtual string piattoInString(piattoBase*) const;

        //overloading operatori
        bool operator==(const piattoBase&) const;
//        bool operator!=(const piattoBase&) const;

};

#endif // PRIMO_H

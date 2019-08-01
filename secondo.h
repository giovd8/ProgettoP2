#ifndef SECONDO_H
#define SECONDO_H
#include "piattobase.h"
#include<QString>
using std::string;

class secondo: public piattoBase {
    private:
        string tipoCarnePesce;
        string tipoPiatto;
    public:
        //costruttore secondo
        secondo(string="", bool=false, bool=true, double=10, string="", string="");

        //costruttore di copia
        secondo(const secondo &);

        //metodi GET
        string getTipoCarnePesce() const;
        string getTipoPiatto() const;

        //metodi SET
        void setTipoCarnePesce(string);
        void setTipoPiatto(string);

        //calcola prezzo finale virtuale
        double prezzoFinale() const;

        //convertire oggetto in stringa
        string piattoInString(piattoBase*) const;

        //overloading operatori
        bool operator==(const piattoBase&) const;
        //bool operator!=(const piattoBase&) const;
};

#endif // SECONDO_H

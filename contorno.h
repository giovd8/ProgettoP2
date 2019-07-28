#ifndef CONTORNO_H
#define CONTORNO_H
#include "piattobase.h"
#include<QString>
using std::string;


class contorno: public piattoBase {
    private:
        string nomeContorno;
        string tipoContorno;
    public:
        //costruttore contorno
        contorno(string="", bool=true, bool=true, double=3.5, string="", string="");

        //costruttore di copia
        contorno(const contorno&);

        //metodi GET
        string getNomeContorno() const;
        string getTipoContorno() const;

        //metodi SET
        void setNomeContorno(string);
        void setTipoContorno(string);

        //calcola prezzo finale virtuale
        double prezzoFinale() const;

        //convertire oggetto in stringa
        string piattoInString(piattoBase*) const;

        //overloading operatori
        bool operator==(const piattoBase&) const;
        //bool operator!=(const piattoBase&) const;
};

#endif // CONTORNO_H

#ifndef MENUITEM_H
#define MENUITEM_H
#include<iostream>
using std::string;

class piattoBase {
    private:
        string nome;
        bool vegano;
        bool glutenFree;
        double prezzoBase;
    public:
        //costruttore piattoBase
        piattoBase(string="",bool=false, bool=false, double=3);

        //costruttore di copia
        piattoBase(const piattoBase &);

        //ditruttore virtuale
        virtual ~piattoBase()=default;

        //metodi GET
        string getNome() const;
        bool isVegano() const;
        bool isGlutenFree() const;
        double getPrezzoBase() const;

        //metodi SET
        void setNome(string);
        void setVegano(bool);
        void setGlutenFree(bool);
        void setPrezzoBase(double);


        //calcola prezzo finale
        virtual double prezzoFinale() const=0;

        //convertire oggetto in stringa
        virtual string piattoInString(piattoBase*) const =0;

        //overloading operatori
        virtual bool operator==(const piattoBase&) const;
//        virtual bool operator!=(const piattoBase&) const;
};
//std::ostream& operator<<(std::ostream&, const piattoBase&);
#endif // MENUITEM_H

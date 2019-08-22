#ifndef MENUITEM_H
#define MENUITEM_H
#include<QString>
#include<iostream>
using std::string;

class piattoBase {
    private:
        string nome;
        bool vegano;
        bool glutenFree;
        double prezzoBase;
        string urlImmagine;
    public:
        //costruttore piattoBase
        piattoBase(string="",bool=false, bool=false, double=3, string="");

        //costruttore di copia
        piattoBase(const piattoBase &);

        //ditruttore virtuale
        virtual ~piattoBase()=default;

        //metodi GET
        string getNome() const;
        bool isVegano() const;
        bool isGlutenFree() const;
        double getPrezzoBase() const;
        string getUrlImmagine() const;

        //metodi SET
        void setNome(string);
        void setVegano(bool);
        void setGlutenFree(bool);
        void setPrezzoBase(double);
        void setUrlImmagine(string);


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

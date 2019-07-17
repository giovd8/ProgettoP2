#include "piattobase.h"
#include "secondo.h"

//costruttore secondo
secondo::secondo(string s, bool v, bool gf, double pr, string tc, string tp, string ts, string cot) : piattoBase(s,v,gf,pr), tipoCarne(tc), tipoPesce(tp), tipoPiatto(ts), tipoCottura(cot) {}

//costruttore di copia
secondo::secondo(const secondo &s) : piattoBase(s), tipoCarne(s.getTipoCarne()), tipoPesce(s.getTipoPesce()), tipoPiatto(s.getTipoPiatto()), tipoCottura(s.getTipoCottura()) {}

//metodi GET
string secondo::getTipoCarne() const {
    return tipoCarne;
}
string secondo::getTipoPesce() const {
    return tipoPesce;
}
string secondo::getTipoPiatto() const {
    return tipoPiatto;
}
string secondo::getTipoCottura() const {
    return tipoCottura;
}

//calcola prezzo finale virtuale
double secondo::prezzoFinale() const {
    double prezzoTemp=getPrezzoBase();
    if(tipoCarne=="maiale")
        prezzoTemp=prezzoTemp+5;
    else
        prezzoTemp=prezzoTemp+10;
    if(tipoPesce=="salmone" || tipoPesce=="seppie")
        prezzoTemp=prezzoTemp+15;
    else
        prezzoTemp=prezzoTemp+10;
    if(tipoPiatto=="costata" || tipoPiatto=="alla griglia")
        prezzoTemp=prezzoTemp+8.5;
    if(tipoPiatto=="filetto")
        prezzoTemp=prezzoTemp+10;
    else
        prezzoTemp=prezzoTemp+5;

    return prezzoTemp;
}

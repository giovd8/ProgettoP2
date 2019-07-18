#include "contorno.h"


//costruttore contorno
contorno::contorno(string s, bool v, bool gf, double pr, bool p, string tc): piattoBase(s,v,gf,pr), patate(p), tipoContorno(tc) {}

//costruttore di copia
contorno::contorno(const contorno &c) : piattoBase(c), patate(c.patate), tipoContorno(c.tipoContorno) {}

//metodi GET
bool contorno::getPatate() const {
    return patate;
}
string contorno::getTipoContorno() const {
    return tipoContorno;
}

//calcola prezzo finale virtuale
double contorno::prezzoFinale() const {
    double prezzoTemp=getPrezzoBase();
    if(patate)
        prezzoTemp=prezzoTemp+3.5;
    else
        prezzoTemp=prezzoTemp+5;

    return prezzoTemp;
}

string contorno::piattoInString(piattoBase* pb) const {
    string strF = piattoBase::piattoInString(pb);
    contorno* x=dynamic_cast<contorno*>(pb);
        if(x && x->getPatate())
            strF.append("/nPatate: ");
        else
            strF.append("/Verdure: ");

    strF.append(x->getTipoContorno());
    return strF;
}


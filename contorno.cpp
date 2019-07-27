#include "contorno.h"


//costruttore contorno
contorno::contorno(string s, bool v, bool gf, double pr, string nc, string tc): piattoBase(s,v,gf,pr), nomeContorno(nc), tipoContorno(tc) {}

//costruttore di copia
contorno::contorno(const contorno &c) : piattoBase(c), nomeContorno(c.nomeContorno), tipoContorno(c.tipoContorno) {}

//metodi GET
string contorno::getNomeContorno() const {
    return nomeContorno;
}
string contorno::getTipoContorno() const {
    return tipoContorno;
}

//metodi SET
void contorno::setNomeContorno(string s){
    nomeContorno=s;
}
void contorno::setTipoContorno(string s){
    tipoContorno=s;
}

//calcola prezzo finale virtuale
double contorno::prezzoFinale() const {
    double prezzoTemp=getPrezzoBase();
    if(nomeContorno=="Verdure")
        prezzoTemp=prezzoTemp+5;
    else
        prezzoTemp=prezzoTemp+3.5;

    return prezzoTemp;
}

string contorno::piattoInString(piattoBase* pb) const {
    string strF = piattoBase::piattoInString(pb);
    contorno* x=dynamic_cast<contorno*>(pb);
    if(x)
        strF.append("\n"+getNomeContorno()+" "+x->getTipoContorno()).append("\nPrezzo: "+ (QString::number(prezzoFinale()).toUtf8())).append("\n");
    return strF;
}

//overloading operatore ==
bool contorno::operator==(const piattoBase& p) const {
    const contorno* c=dynamic_cast<const contorno*>(&p);
    return c && piattoBase::operator==(p) && nomeContorno==c->getNomeContorno() && tipoContorno==c->getTipoContorno();
}


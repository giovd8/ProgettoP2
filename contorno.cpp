#include "contorno.h"


//costruttore contorno
contorno::contorno(string s, bool v, bool gf, double pr, string ui, string tc): piattoBase(s,v,gf,pr,ui), tipoContorno(tc) {}

//costruttore di copia
contorno::contorno(const contorno &c) : piattoBase(c), tipoContorno(c.tipoContorno) {}

//metodi GET
string contorno::getTipoContorno() const {
    return tipoContorno;
}

//metodi SET
void contorno::setTipoContorno(string s){
    tipoContorno=s;
}

//calcola prezzo finale virtuale
double contorno::prezzoFinale() const {
    double prezzoTemp=getPrezzoBase();
    if(getNome()=="Verdure")
        prezzoTemp=prezzoTemp+5;
    else
        prezzoTemp=prezzoTemp+3.5;

    return prezzoTemp;
}

string contorno::piattoInString(piattoBase* pb) const {
    string strF = piattoBase::piattoInString(pb);
    contorno* x=dynamic_cast<contorno*>(pb);
    if(x)
        strF.append("\nTipo di contorno: "+getNome()+" "+x->getTipoContorno()).append("\nPrezzo: "+ (QString::number(prezzoFinale()).toUtf8())).append("\n");
    return strF;
}

//overloading operatore ==
bool contorno::operator==(const piattoBase& p) const {
    const contorno* c=dynamic_cast<const contorno*>(&p);
    return c && piattoBase::operator==(p) && (tipoContorno==c->getTipoContorno() || c->getTipoContorno()=="");
}


#include "piattobase.h"
#include "secondo.h"

//costruttore secondo
secondo::secondo(string s, bool v, bool gf, double pr, string tc, string tp, string ts) : piattoBase(s,v,gf,pr), tipoCarne(tc), tipoPesce(tp), tipoPiatto(ts) {}

//costruttore di copia
secondo::secondo(const secondo &s) : piattoBase(s), tipoCarne(s.getTipoCarne()), tipoPesce(s.getTipoPesce()), tipoPiatto(s.getTipoPiatto()) {}

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

//metodi SET
void secondo::setTipoCarne(string s){
    tipoCarne=s;
}
void secondo::setTipoPesce(string s){
    tipoPesce=s;
}
void secondo::setTipoPiatto(string s){
    tipoPiatto=s;
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

string secondo::piattoInString(piattoBase* pb) const {
    string strF = piattoBase::piattoInString(pb);
    secondo* x=dynamic_cast<secondo*>(pb);
    if(x){
        if(x->getTipoCarne()!="")
            strF.append("\nTipo di carne: " + x->getTipoCarne());
        else
            strF.append("\nTipo di pesce: " + x->getTipoPesce());
    strF.append("\nTipo di piatto: "+x->getTipoPiatto()).append("\nPrezzo: "+ (QString::number(prezzoFinale()).toUtf8())).append("\n");

    }
    return strF;
}

bool secondo::operator==(const piattoBase& p) const {
    const secondo* s=dynamic_cast<const secondo*>(&p);
    return s && piattoBase::operator==(p) && (tipoCarne==s->getTipoCarne() || s->getTipoCarne()=="") && (tipoPesce==s->getTipoPesce() || s->getTipoPesce()=="") && (tipoPiatto==s->getTipoPiatto() || s->getTipoPiatto()=="");
}

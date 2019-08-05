#include "piattobase.h"
#include "secondo.h"

//costruttore secondo
secondo::secondo(string s, bool v, bool gf, double pr, string ui, string tcp, string tp) : piattoBase(s,v,gf,pr,ui), tipoCarnePesce(tcp), tipoPiatto(tp) {}

//costruttore di copia
secondo::secondo(const secondo &s) : piattoBase(s), tipoCarnePesce(s.getTipoCarnePesce()), tipoPiatto(s.getTipoPiatto()) {}

//metodi GET
string secondo::getTipoCarnePesce() const {
    return tipoCarnePesce;
}
string secondo::getTipoPiatto() const {
    return tipoPiatto;
}

//metodi SET
void secondo::setTipoCarnePesce(string s){
    tipoCarnePesce=s;
}
void secondo::setTipoPiatto(string s){
    tipoPiatto=s;
}


//calcola prezzo finale virtuale
double secondo::prezzoFinale() const {
    double prezzoTemp=getPrezzoBase();
    if(tipoCarnePesce=="maiale")
        prezzoTemp=prezzoTemp+3;
    if(tipoCarnePesce=="manzo" || tipoCarnePesce=="agnello")
        prezzoTemp=prezzoTemp+5;
    if(tipoCarnePesce=="salmone" || tipoCarnePesce=="seppie")
        prezzoTemp=prezzoTemp+8;
    if(piattoBase::getNome()=="costata")
        prezzoTemp=prezzoTemp+5;
    if(piattoBase::getNome()=="filetto")
        prezzoTemp=prezzoTemp+10;
    return prezzoTemp;
}

string secondo::piattoInString(piattoBase* pb) const {
    string strF = piattoBase::piattoInString(pb);
    secondo* x=dynamic_cast<secondo*>(pb);
    if(x){
        if(x->piattoBase::getNome()!="")
            strF.append("\nTipo di secondo: " +x->piattoBase::getNome()).append(" di " + x->getTipoCarnePesce());
    strF.append(" "+x->getTipoPiatto()).append("\nPrezzo: "+ (QString::number(prezzoFinale()).toUtf8())).append("\n");

    }
    return strF;
}

bool secondo::operator==(const piattoBase& p) const {
    const secondo* s=dynamic_cast<const secondo*>(&p);
    return s && piattoBase::operator==(p) && (tipoCarnePesce==s->getTipoCarnePesce() || s->getTipoCarnePesce()=="") && (tipoPiatto==s->getTipoPiatto() || s->getTipoPiatto()=="");
}

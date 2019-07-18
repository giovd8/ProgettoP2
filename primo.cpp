#include "piattobase.h"
#include "primo.h"
#include <iostream>
using std::string;

//costruttore
primo::primo(string n, bool v, bool gf, double pr, bool so, string tp, string i1, string i2, string i3, string i4): piattoBase(n,v,gf,pr), soia(so), tipoPasta(tp), ingrediente1(i1), ingrediente2(i2), ingrediente3(i3), ingrediente4(i4) {}

//costruttore di copia
primo::primo(const primo& p) : piattoBase(p), soia(p.getSoia()), tipoPasta(p.getPasta()), ingrediente1(p.getIngrediente1()), ingrediente2(p.getIngrediente2()), ingrediente3(p.getIngrediente3()), ingrediente4(p.getIngrediente4()) {}

//metodi GET
bool primo::getSoia() const {
    return soia;
}
string primo::getPasta()const {
    return tipoPasta;
}
string primo::getIngrediente1() const {
    return ingrediente1;
}
string primo::getIngrediente2() const {
    return ingrediente2;
}
string primo::getIngrediente3() const {
    return ingrediente3;
}
string primo::getIngrediente4() const {
    return ingrediente4;
}

//calcola prezzo finale virtuale
double primo::prezzoFinale() const {
    double prezzoTemp=getPrezzoBase();
    if(ingrediente1 == "gamberi")
        prezzoTemp=prezzoTemp+2;
    if(ingrediente1 == "pancetta")
        prezzoTemp=prezzoTemp+1.5;
    if(ingrediente1 =="")
        prezzoTemp=prezzoTemp+1;

    if(ingrediente2 == "gamberi")
        prezzoTemp=prezzoTemp+2;
    if(ingrediente2 == "pancetta")
        prezzoTemp=prezzoTemp+1.5;
    if(ingrediente2 == "")

        prezzoTemp=prezzoTemp+1;
    if(ingrediente3 == "gamberi")
        prezzoTemp=prezzoTemp+2;
    if(ingrediente3 == "pancetta")
        prezzoTemp=prezzoTemp+1.5;
    if(ingrediente3 == "")
        prezzoTemp=prezzoTemp+1;

    if(ingrediente4 == "gamberi")
        prezzoTemp=prezzoTemp+2;
    if(ingrediente4 == "pancetta")
        prezzoTemp=prezzoTemp+1.5;
    if(ingrediente4 == "")
        prezzoTemp=prezzoTemp+1;

    return prezzoTemp;
}

string primo::piattoInString(piattoBase* pb) const {
    string strF = piattoBase::piattoInString(pb);
    primo* x=dynamic_cast<primo*>(pb);
    if(x){
        if(x->getSoia())
            strF.append("\nPasta di soia: si");
        else
            strF.append("\nPasta di soia: no");
    strF.append("\nTipo di Pasta: " + x->getPasta()).append("\nIgredienti: " +x->getIngrediente1());
    if(x->getIngrediente2()!="")
        strF.append(" "+x->getIngrediente2());
        if(x->getIngrediente3()!="")
            strF.append(" "+x->getIngrediente3());
            if(x->getIngrediente4()!="")
                strF.append(" "+x->getIngrediente4());
    }
    return strF;
}


#include"piattobase.h"
#include"primo.h"
#include"secondo.h"
#include"contorno.h"

//costruttore piattoBase
piattoBase::piattoBase(string n,bool v, bool gf, double pr, string ui): nome(n), vegano(v), glutenFree(gf), prezzoBase(pr), urlImmagine(ui){}

//cotruttore di copia
piattoBase::piattoBase(const piattoBase& p) : nome(p.getNome()), vegano(p.isVegano()), glutenFree(p.isGlutenFree()), prezzoBase(p.getPrezzoBase()), urlImmagine(p.getUrlImmagine()) {}

//metodi GET
string piattoBase::getNome() const {
    return nome;
}
bool piattoBase::isVegano() const {
    return vegano;
}
bool piattoBase::isGlutenFree() const {
    return glutenFree;
}
double piattoBase::getPrezzoBase() const {
    return prezzoBase;
}
string piattoBase::getUrlImmagine() const {
    return urlImmagine;
}

//metodi SET
void piattoBase::setNome(string s) {
    nome=s;
}
void piattoBase::setVegano(bool b) {
    vegano=b;
}
void piattoBase::setGlutenFree(bool b) {
    glutenFree=b;
}
void piattoBase::setPrezzoBase(double d) {
    prezzoBase=d;
}
void piattoBase::setUrlImmagine(string s) {
    urlImmagine=s;
}

//Metodo per convertire il mio oggetto in una string
string piattoBase::piattoInString(piattoBase* pb) const {
    string ptString;
    if(dynamic_cast<primo*>(pb))
        ptString="Primo";
    if(dynamic_cast<secondo*>(pb))
        ptString="Secondo";
    if(dynamic_cast<contorno*>(pb))
        ptString="Contorno";
    string strF = "";
    //strF.append("Tipo di piatto: " + ptString)
    strF.append("Nome: " + getNome());
    if(pb->isGlutenFree())
        strF.append("\nGluten free: si");
    else
        strF.append("\nGluten free: no");
    if(pb->isVegano())
        strF.append("     Vegano: si");
    else
        strF.append("     Vegano: no");
    return strF;
}

//overloading operatori
bool piattoBase::operator==(const piattoBase& p) const{
    return ((nome==p.getNome() || p.getNome()=="") && (vegano==p.isVegano() || p.isVegano()==false) && (glutenFree==p.isGlutenFree() || p.isGlutenFree()==false) && (prezzoBase==p.getPrezzoBase() || p.getPrezzoBase()==0));
}

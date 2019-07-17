#include "piattobase.h"
using std::string;

//costruttore piattoBase
piattoBase::piattoBase(string n,bool v, bool gf, double pr): nome(n), vegano(v), glutenFree(gf), prezzoBase(pr){}

//cotruttore di copia
piattoBase::piattoBase(const piattoBase& p) : nome(p.getNome()), vegano(p.getVegano()), glutenFree(p.getGlutenFree()), prezzoBase(p.getPrezzoBase()) {}

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

//metodi GET
string piattoBase::getNome() const {
    return nome;
}
bool piattoBase::getVegano() const {
    return vegano;
}
bool piattoBase::getGlutenFree() const {
    return glutenFree;
}
bool piattoBase::getPrezzoBase() const {
    return prezzoBase;
}

//overloading operatori
//virtual std::ostream& operator<< (std::ostream& OS, const piattoBase& pb) {
//    if(pb.getGlutenFree())
//        std::cout<<"Senza glutine: si"<<" ";
//    else
//        std::cout<<"Senza glutine: no"<<" ";
//    if(pb.getVegano())
//        std::cout<<"Vegano: si"<<" ";
//    else
//        std::cout<<"Vegano: no"<<" ";
//    return OS;
//}


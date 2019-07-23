#include "piattobase.h"
#include"primo.h"
#include"secondo.h"
#include"contorno.h"
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
bool piattoBase::operator==(const piattoBase& p) const{
    return (nome==p.getNome() && vegano==p.getVegano() && glutenFree==p.getGlutenFree() && prezzoBase==p.getPrezzoBase());
}

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
    strF.append("Tipo di piatto: " + ptString)
            .append("\nNome: " + getNome());
    if(pb->getGlutenFree())
        strF.append("\nGluten free: si");
    else
        strF.append("\nGluten free: no");
    if(pb->getVegano())
        strF.append("     Vegano: si");
    else
        strF.append("     Vegano: no");
    return strF;
}

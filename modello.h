#ifndef MODELLO_H
#define MODELLO_H
#include"container.h"
#include"piattobase.h"
using std::string;


class modello {
    private:
        container<piattoBase*> *piatti;
        string xmlFile;
    public:
        modello(string = ":/PiattiMenu");
        ~modello();

        void caricamentoDati() const;
};

#endif // MODELLO_H

#include <iostream>
#include "container.h"
#include "piattobase.h"
#include "primo.h"
#include "secondo.h"
#include "contorno.h"
#include <string.h>
#include <QApplication>
#include<controller.h>
//#include <qtGui/QApplication>

using namespace std;


//int main() {
//    container<piattoBase*> x;
//    piattoBase * t1 = new primo(true,true,5,true,"penne","pomodoro","pesto");
//    piattoBase * t2 = new secondo(false,false,15,"maiale","","costata","media");
//    piattoBase * t3 = new contorno(false,false,10,false,"chips");
//    x.pushBegin(t1);
//    x.pushEnd(t2);
//    x.pushEnd(t3);
//    container<piattoBase*>::iteratore it=x.begin();
//    for(; it!=x.end(); ++it){
//         primo* temp=dynamic_cast<primo*>(*it);
//         secondo* temp2=dynamic_cast<secondo*>(*it);
//         contorno* temp3=dynamic_cast<contorno*>(*it);

//         if(temp) {
//             cout<<endl;
//             cout<<(temp->getVegano());
//             cout<<endl;
//             cout<<(temp->getPasta());
//             cout<<endl;
//             cout<<(temp->getIngrediente1());
//             cout<<endl;
//             cout<<(temp->getIngrediente2());
//             cout<<endl;
//             cout<<(temp->getIngrediente3());
//             cout<<endl;
//             cout<<(temp->getIngrediente4());
//             cout<<endl;
//           }
//         if(temp2){

//             cout<<endl;
//             cout<<(temp2->getVegano());
//             cout<<endl;
//             cout<<(temp2->getTipoCarne());
//             cout<<endl;
//             cout<<(temp2->getTipoCottura());
//             cout<<endl;
//             cout<<(temp2->getTipoPiatto());
//             cout<<endl;

//         }
//         if(temp3){

//             x.erase(it);
//             --it;
//         }
//         else {
//             cout<<endl;
//             cout<<(temp3->getPatate());
//             cout<<endl;
//             cout<<(temp3->getTipoContorno());
//             cout<<endl;
//         }


//    }

//}
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    controller w(nullptr);
    w.show();

    return app.exec();
}


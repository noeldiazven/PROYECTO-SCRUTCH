#include<iostream>
#include "types.h"
#include "prueba.h"
#include "smart_pointer.h"
#include "recta.h"

using namespace std;

int main(){
   prueba <int>uno(5,6);

    uno.Display();
    cout<<uno.sumar_valores(4,4)<<endl;
    T resultado;
    uno.multiplicar_valores(&resultado);
    cout<<resultado<<endl;
    //////////////////////////////////////////
    //////Prueba de punteros inteligentes////
    ////////////////////////////////////////

    smart_pointer <recta> r1(new recta(3,1));
    r1->display_r();




    return 0;
}

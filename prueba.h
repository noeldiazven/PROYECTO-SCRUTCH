#ifndef PRUEBA_H
#define PRUEBA_H
#include "types.h"
#include<iostream>

using namespace std;

template<typename valor>

class prueba{

    valor x;
    valor y;

public:

    prueba(valor eje_x=0,valor eje_Y=0){
        x=eje_x;
        y=eje_Y;
    }

    valor sumar_valores(valor,valor);
    void multiplicar_valores(T*);
    void Display(){ cout<< x<< "," <<y<<endl; }
};

template<typename valor>
valor prueba<valor>::sumar_valores(valor a,valor b){
    return a+b;
}

template<typename valor>
void prueba<valor>::multiplicar_valores(T * resultado){
    *resultado=x*y;
}

#endif // PRUEBA_H

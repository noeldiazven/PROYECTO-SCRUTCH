#ifndef MENOR_MAYOR_H
#define MENOR_MAYOR_H

#include "bloques.h"
#include "tipos.h"
class Menor_mayor:public Bloques
{
private:
    entero comp1,comp2;
    Menor_mayor *entrada;

public:
    Menor_mayor(Gato * g,ventanabotones * v);
    void crear_nuevo();
    void correr();
};

#endif // MENOR_MAYOR_H

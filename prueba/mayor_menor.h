#ifndef MAYOR_MENOR_H
#define MAYOR_MENOR_H

#include "bloques.h"
#include "tipos.h"


class Mayor_menor: public Bloques
{
private:
    entero comp1,comp2;
    Mayor_menor *entrada;

public:
    Mayor_menor(Gato * g,ventanabotones * v);
    void crear_nuevo();
    void correr();
};

#endif // MAYOR_MENOR_H

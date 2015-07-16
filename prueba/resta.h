#ifndef RESTA_H
#define RESTA_H

#include "tipos.h"
#include "bloques.h"


class Resta:public Bloques
{
public:
private:
    entero valor1,valor2;
    Resta *entrada;

public:
    Resta(Gato * g,ventanabotones * v);
    void crear_nuevo();
    void correr();
    virtual QString darValores();
};

#endif // RESTA_H

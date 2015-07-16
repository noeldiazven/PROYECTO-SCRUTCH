#ifndef SUMA_H
#define SUMA_H

#include "bloques.h"
#include "tipos.h"

class Suma: public Bloques{

private:
    entero valor1,valor2;
    Suma *entrada;



public:
    Suma(Gato * g,ventanabotones * v);
    void crear_nuevo();
    void correr();
    virtual QString darValores();
};

#endif // SUMA_H

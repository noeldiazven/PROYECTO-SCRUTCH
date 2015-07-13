#ifndef MULTIPLICACION_H
#define MULTIPLICACION_H

#include "tipos.h"
#include "bloques.h"


class Multiplicacion:public Bloques
{
public:
private:
    entero valor1,valor2;
    Multiplicacion *entrada;

public:
    Multiplicacion(Gato * g,ventanabotones * v);
    void crear_nuevo();
    void correr();
};

#endif // MULTIPLICACION_H

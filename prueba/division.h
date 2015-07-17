#ifndef DIVISION_H
#define DIVISION_H

#include "tipos.h"
#include "bloques.h"


class Division:public Bloques
{
private:
    entero valor1,valor2;
    Division *entrada;



public:
    Division(Gato * g,ventanabotones * v);
    void crear_nuevo();
    void correr();
    virtual QString darValores();
    virtual void abrir(QTextStream & text);
};

#endif // DIVISION_H

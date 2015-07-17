#ifndef IGUAL_H
#define IGUAL_H

#include "bloques.h"
#include "tipos.h"

class Igual: public Bloques{

private:
    entero comp1,comp2;
    Igual *entrada;



public:
    Igual(Gato * g,ventanabotones * v);
    void crear_nuevo();
    void correr();
    virtual QString darValores();
    virtual void abrir(QTextStream & text);

};

#endif // IGUAL_H

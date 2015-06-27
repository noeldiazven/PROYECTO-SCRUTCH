#ifndef ANGULO_H
#define ANGULO_H
#include "gato.h"
#include "bloques.h"

typedef double(dobles);
class Angulo: public Bloques{
private:
    dobles direccion;
    dobles pi=3.14159265358979323846;
public:
    Angulo(Gato *g,ventanabotones * v);
    void rotateLabel();
    void crear_nuevo();
    void correr();
};

#endif // ANGULO_H

#ifndef UNICADIRECCION_H
#define UNICADIRECCION_H
#include "gato.h"
#include "bloques.h"
#include "angulo.h"

class UnicaDireccion:public Bloques{
private:
    dobles direccion_secundaria;
    dobles pi=3.14159265358979323846;
public:
    UnicaDireccion(Gato *g,QWidget * v);

    void crear_nuevo();
    void correr();
    void cambiar_direccion();
};
#endif // UNICADIRECCION_H

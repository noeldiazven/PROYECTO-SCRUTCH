#ifndef ANGULO_H
#define ANGULO_H

#include "tipos.h"
#include "bloques.h"

class Angulo: public Bloques{
private:
    dobles direccion;
    dobles pi=3.14159265358979323846;
    dobles dx;
    dobles dy;
public:
    Angulo(Gato *g,ventanabotones * v,ventanamostrador *venta);

    void rotateLabel();
    void crear_nuevo();
    void correr();
    void rotacion_en_el_plano();
};

#endif // ANGULO_H

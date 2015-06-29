#ifndef GIRARDERECHA_H
#define GIRARDERECHA_H

#include "bloques.h"
#include "tipos.h"

class GirarDerecha: public Bloques{
private:
    dobles direccion;
    dobles pi=3.14159265358979323846;
    dobles dx;
    dobles dy;
public:
    GirarDerecha(Gato *g, ventanabotones * v);

    void rotateLabel();
    void crear_nuevo();
    void correr();
    void rotacion_en_el_plano();
};
#endif // GIRARDERECHA_H

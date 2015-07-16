#ifndef UNICADIRECCION_H
#define UNICADIRECCION_H


#include "bloques.h"
#include "tipos.h"

class UnicaDireccion: public Bloques{
private:
    dobles direccion;
    dobles pi=3.14159265358979323846;
    dobles dx;
    dobles dy;
public:
    UnicaDireccion(Gato *g, ventanabotones * v,ventanamostrador*venta);

    void rotateLabel();
    void crear_nuevo();
    void correr();
    void rotacion_en_el_plano();
    virtual QString darValores();
};

#endif // UNICADIRECCION_H

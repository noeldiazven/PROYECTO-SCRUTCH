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
    GirarDerecha(Gato *g, ventanabotones * v,ventanamostrador*venta);

    void rotateLabel();
    void crear_nuevo();
    void correr();
    virtual void abrir(QTextStream & text);
    void rotacion_en_el_plano();
    virtual QString darValores();
};
#endif // GIRARDERECHA_H

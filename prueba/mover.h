#ifndef MOVER
#define MOVER
#include "bloques.h"
#include "punto.h"
class Mover:public Bloques{
private:
    entero pasos;
    Mover *entrada;

public:
    Mover(Gato * g,ventanabotones * v,ventanamostrador*venta);
    void crear_nuevo();
    void correr();
    virtual QString darValores();
};
#endif // MOVER

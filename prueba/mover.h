#ifndef MOVER
#define MOVER
#include "bloques.h"

class Mover:public Bloques{
private:
    entero pasos;
    Mover *entrada;

public:
    Mover(Gato * g,ventanabotones * v);
    void crear_nuevo();
    void correr();
};
#endif // MOVER

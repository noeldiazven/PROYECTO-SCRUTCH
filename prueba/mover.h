#ifndef MOVER
#define MOVER
#include "gato.h"
#include "bloques.h"

class Mover:public Bloques{
private:
    entero pasos;
    Mover *entrada;
public:
    Mover(Gato * g);
    void correr();
};
#endif // MOVER

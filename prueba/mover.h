#ifndef MOVER
#define MOVER
#include "gato.h"
#include "bloques.h"
#include <QWidget>

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

#ifndef INICIO_H
#define INICIO_H
#include "bloques.h"

class inicio:public Bloques
{
public:
    inicio(Gato *g,ventanabotones * v);
    void correr();
    void crear_nuevo();
};

#endif // INICIO_H

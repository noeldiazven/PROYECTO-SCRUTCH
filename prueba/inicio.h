#ifndef INICIO_H
#define INICIO_H
#include "bloques.h"

class inicio:public Bloques
{
public:
    inicio(Gato *g,ventanabotones * v);
    void correr();
    void crear_nuevo();
    virtual QString darValores();
    virtual void abrir(QTextStream & text);
};

#endif // INICIO_H

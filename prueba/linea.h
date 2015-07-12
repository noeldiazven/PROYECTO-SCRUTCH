#ifndef LINEA_H
#define LINEA_H

#include "tipos.h"
#include "bloques.h"

class Linea: public Bloques{
private:
    dobles direccion;
    dobles pi=3.14159265358979323846;
    dobles dx;
    dobles dy;
public:
    Linea(Gato *g,ventanabotones * v);
};

#endif // LINEA_H


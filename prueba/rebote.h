#ifndef REBOTE_H
#define REBOTE_H

#include "bloques.h"
#include "tipos.h"
#include <QtCore/qglobal.h>

class Rebote:public Bloques{
private:
    entero posicionar_en_x;
    entero posicionar_en_y;
    dobles direccion;
    dobles pi=3.14159265358979323846;
    dobles dx;
    dobles dy;
public:

    void set_posicionar_en_x(entero valor){posicionar_en_x=valor;}
    void set_posicionar_en_y(entero valor){posicionar_en_y=valor;}
    entero get_posicion_en_x(){return posicionar_en_x;}
    entero get_posicion_en_y(){return posicionar_en_y;}

    Rebote(Gato *g, ventanabotones * v);
    void rotateLabel();
    void crear_nuevo();
    void correr();
    void rotacion_en_el_plano();
    virtual QString darValores();
};


#endif // REBOTE_H

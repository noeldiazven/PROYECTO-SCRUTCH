#ifndef POSICIONARGATOEN_H
#define POSICIONARGATOEN_H
#include "bloques.h"
#include "tipos.h"
#include <QtCore/qglobal.h>

class PosicionarGatoEn:public Bloques{
private:
    entero posicionar_en_x;
    entero posicionar_en_y;
    tipo_entero direccion;
    tipo_entero direccion1;
public:

    void set_posicionar_en_x(entero valor){posicionar_en_x=valor;}
    void set_posicionar_en_y(entero valor){posicionar_en_y=valor;}
    entero get_posicion_en_x(){return posicionar_en_x;}
    entero get_posicion_en_y(){return posicionar_en_y;}

    PosicionarGatoEn(Gato *g, ventanabotones * v);
    void rotateLabel();
    void crear_nuevo();
    void correr();
    virtual QString darValores();
    virtual void abrir(QTextStream & text);
};

#endif // POSICIONARGATOEN_H

#ifndef COLOR_H
#define COLOR_H

#include <QtCore/qglobal.h>

#include <QPainter>
#include <QtCore>
#include <QtCore/qglobal.h>
#include "tipos.h"
#include "bloques.h"

#include "ventanamostrador.h"
#include "botones.h"
#include "linea.h"


class color: public Bloques{
private:
    dobles direccion;
    dobles pi=3.14159265358979323846;
    dobles dx;
    dobles dy;
    QWidget *operaciones;



public:
    color(Gato *g, ventanabotones * v);

    void rotateLabel();
    void crear_nuevo();
    void correr();


};

#endif // COLOR_H

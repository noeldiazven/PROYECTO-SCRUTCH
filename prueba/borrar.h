#ifndef BORRAR_H
#define BORRAR_H

#include <QtCore/qglobal.h>

#include <QPainter>
#include <QtCore>
#include <QtCore/qglobal.h>
#include "tipos.h"
#include "bloques.h"

#include "ventanamostrador.h"
#include "botones.h"
#include "linea.h"

class Borrar: public Bloques{
private:
    dobles direccion;
    dobles pi=3.14159265358979323846;
    dobles dx;
    dobles dy;
    QWidget *operaciones;



public:
    Borrar(Gato *g, ventanabotones * v,ventanamostrador*venta);

    void rotateLabel();
    void crear_nuevo();
    void correr();
    void rotacion_en_el_plano();
    void pintar_imagen();
    void paintEvent();


};


#endif // BORRAR_H

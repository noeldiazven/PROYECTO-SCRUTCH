#ifndef BAJARLAPIZ_H
#define BAJARLAPIZ_H

#include <QPainter>
#include <QtCore>
#include <QtCore/qglobal.h>
#include "tipos.h"
#include "bloques.h"

#include "ventanamostrador.h"
#include "botones.h"
#include "linea.h"

class BajarLapiz: public Bloques{
private:
    dobles direccion;
    dobles pi=3.14159265358979323846;
    dobles dx;
    dobles dy;
    QWidget *operaciones;



public:
    BajarLapiz(Gato *g, ventanabotones * v);

    void rotateLabel();
    void crear_nuevo();
    void correr();
    void rotacion_en_el_plano();
    void pintar_imagen();
    void paintEvent();
    virtual QString darValores();


};

#endif // BAJARLAPIZ_H

#ifndef BOTONABRIR_H
#define BOTONABRIR_H
#include <QLabel>
#include "gato.h"
#include "botonguardar.h"
#include "ventanabotones.h"

class botonabrir:public QLabel
{
private:
    Gato * gato;
    botonguardar * b_guardar;
    buleo abrir=false;
    entero posX,posY,width,height;
    ventanabotones * botones;
public:
    botonabrir(Gato * g, QLabel * parent, botonguardar * guardar, ventanabotones *b);
    void mousePressEvent(QMouseEvent * evento);
    void abrirDatos(QTextStream &a);
};

#endif // BOTONABRIR_H

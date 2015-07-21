#ifndef PUNTOS_H
#define PUNTOS_H

#include <QtCore/qglobal.h>
#include <QLabel>
#include <QMatrix>
#include "tipos.h"

class Puntos{
private:
    QWidget * second;
    dobles dx;
    dobles dy;
    entero largo=200;
    entero ancho=100;
public:
    Puntos(QWidget *par);

};

#endif // PUNTOS_H

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
public:
    Puntos(QWidget *par);

};

#endif // PUNTOS_H

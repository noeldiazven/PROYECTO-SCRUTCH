#ifndef PUNTO_H
#define PUNTO_H

#include <QtCore/qglobal.h>

#include <QLabel>
#include <QMatrix>
#include "gato.h"
#include "tipos.h"
class Bloques;
class Punto: public QLabel{
private:
    QWidget * second;
    QPixmap imagen;
    dobles dx;
    dobles dy;
    Gato*hola;
public:
    Punto(Gato *g, QWidget *par, entero x, entero y);
    void create_nuevo();

};
#endif // PUNTO_H

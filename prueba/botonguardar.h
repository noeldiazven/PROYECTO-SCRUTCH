#ifndef BOTONGUARDAR_H
#define BOTONGUARDAR_H
#include <QLabel>
#include "gato.h"

class botonguardar:public QLabel
{
private:
    Gato * gato;
public:
    botonguardar(Gato * g,QLabel * parent);
    void mousePressEvent(QMouseEvent * evento);
};

#endif // BOTONGUARDAR_H

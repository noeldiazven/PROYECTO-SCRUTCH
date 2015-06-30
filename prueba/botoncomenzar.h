#ifndef BOTONCOMENZAR_H
#define BOTONCOMENZAR_H
#include <QLabel>
#include "gato.h"

class botoncomenzar:public QLabel
{
private:
    Gato * gato;
public:
    botoncomenzar(Gato * g,QLabel * parent);
    void mousePressEvent(QMouseEvent * evento);
    void mouseReleaseEvent(QMouseEvent * evento);
};


#endif // BOTONCOMENZAR_H

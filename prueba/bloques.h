#ifndef BLOQUES
#define BLOQUES
#include <QLabel>
#include "gato.h"

class Bloques:public QLabel{
protected:
    entero mover_x;entero mover_y;
    virtual void mouseDoubleClickEvent(){}//evento del doble click
    void mouseMoveEvent(QMouseEvent * evento);
    //void mouseReleaseEvent(QMouseEvent * evento);
    entero get_mover_x();
    entero get_mover_y();
    void set_mover_x(entero valor);
    void set_mover_y(entero valor);
    void mover(entero a, entero b);
};
#endif // BLOQUES


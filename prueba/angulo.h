#ifndef ANGULO_H
#define ANGULO_H
#include <QtCore/qglobal.h>
#include<QWidget>
#include "gato.h"
#include <QMouseEvent>
#include <QTextEdit>
class Angulo: public QWidget{
private:
    int pasos;
    Gato * obj;
    QTextEdit * setpasos;
    entero mover_x;entero mover_y;
public:
    Angulo(Gato *g);
    entero get_mover_x();
    entero get_mover_y();
    void set_mover_x(entero valor);
    void set_mover_y(entero valor);

    void mover(entero x,entero y);
    void mouseDoubleClickEvent( QMouseEvent * event );//evento del doble click
    void mouseMoveEvent(QMouseEvent * event);
};

#endif // ANGULO_H

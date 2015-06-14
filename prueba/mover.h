#ifndef MOVER
#define MOVER
#include<QWidget>
#include "gato.h"
#include <QMouseEvent>
#include <QTextEdit>

class Mover: public QWidget{
private:
    int pasos;
    Mover *entrada;
    Gato * obj;//puntero al gato
    QTextEdit * setpasos;
    entero mover_x;entero mover_y;
    int d=0 ;
    int  i=0;
public:
    Mover(Gato * g);
    entero get_mover_x();
    entero get_mover_y();
    entero get_d();
    entero get_i();
    void set_d(entero valor);
    void set_i(entero valor);

    void set_mover_x(entero valor);
    void set_mover_y(entero valor);

    void mover_gato(entero x,entero y);
    void mouseDoubleClickEvent( QMouseEvent * evento );//evento del doble click
    void mouseMoveEvent(QMouseEvent * evento);
};
#endif // MOVER


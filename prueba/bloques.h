#ifndef BLOQUES
#define BLOQUES
#include <QLabel>
#include <vector>
#include <QTextEdit>
#include "gato.h"

class Bloques:public QLabel{
protected:
    Gato * obj;
    Bloques * siguiente;
    QTextEdit * setpasos;
    entero x_inicial,y_inicial;
    entero mover_x;entero mover_y;
    entero varianza_up_x,varianza_up_y;     //varianza de los puntos de enlace
    entero varianza_back_x,varianza_back_y; //arriba y abajo
    entero pointer_up_x,pointer_up_y;     //x,y del punto de enlaze arriba
    entero pointer_back_x,pointer_back_y; //x,y del punto de enlaze de abajo

    virtual void correr(){}
    void mover(entero a, entero b);
    void mouseMoveEvent(QMouseEvent * evento);
    void mouseReleaseEvent(QMouseEvent * evento);
    void mouseDoubleClickEvent(QMouseEvent * evento);//evento del doble click
public:
    void set_siguiente(Bloques * nuevo){siguiente=nuevo;}
    Bloques * get_siguiente(){return siguiente;}
    entero get_mover_x();
    entero get_mover_y();
    void set_mover_x(entero valor);
    void set_mover_y(entero valor);
    entero get_pointer_back_x(){return pointer_back_x;}
    entero get_pointer_back_y(){return pointer_back_y;}
    entero get_pointer_up_x(){return pointer_up_x;}
    entero get_pointer_up_y(){return pointer_up_y;}
};
#endif // BLOQUES


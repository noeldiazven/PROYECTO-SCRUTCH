#ifndef BLOQUES
#define BLOQUES
#include <QLabel>
#include <QTextEdit>
#include "gato.h"

class Bloques:public QLabel{
protected:
    QWidget * ventana; //ventana donde se crean los bloques
    Gato * obj; //objecto que se modificara
    Bloques * siguiente; //puntero que apunta al bloque de abajo
    QTextEdit * setpasos; //variable que guarda el valor insertado del usuario
    //Posiciones x,y
    entero mover_x;entero mover_y;

    entero varianza_up_x,varianza_up_y;     //varianza de los puntos de enlace
    entero varianza_back_x,varianza_back_y; //arriba y abajo
    entero pointer_up_x,pointer_up_y;     //x,y del punto de enlaze arriba
    entero pointer_back_x,pointer_back_y; //x,y del punto de enlaze de abajo

    virtual void crear_nuevo(){}
    //posiciones iniciales no varian 'variables temporales'
    entero x_inicial,y_inicial;
    void mover(entero a, entero b);
    //EVENTOS DEL MOUSE
    void mouseMoveEvent(QMouseEvent * evento);
    void mouseReleaseEvent(QMouseEvent * evento);
    void mouseDoubleClickEvent(QMouseEvent * evento);//evento del doble click
    void mousePressEvent(QMouseEvent * evento);

public:
    virtual void correr(){}
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
    ~Bloques(){delete(this);}
};
#endif // BLOQUES


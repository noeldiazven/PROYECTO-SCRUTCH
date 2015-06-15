#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<QWidget>
#include "gato.h"
#include <QMouseEvent>
#include <QTextEdit>

class Funciones: public QWidget
{
private:

public:
    Gato * obj;
    QTextEdit * setpasos;
    entero mover_x;entero mover_y;
    Funciones();
};

#endif // FUNCIONES_H

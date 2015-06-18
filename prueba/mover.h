#ifndef MOVER
#define MOVER
#include<QWidget>
#include "gato.h"
#include "bloques.h"
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QTextEdit>
#include <QLabel>

class Mover:public Bloques{
private:
    entero pasos;
    Mover *entrada;
    Gato * obj;//puntero al gato
    QTextEdit * setpasos;
public:
    Mover(Gato * g);
    void mouseDoubleClickEvent(QMouseEvent * evento);//evento del doble click
};
#endif // MOVER

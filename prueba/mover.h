#ifndef MOVER
#define MOVER
#include<QWidget>
#include "gato.h"
#include <QMouseEvent>
#include <QTextEdit>

class Mover: public QWidget{
private:
    int pasos;
    Gato * obj;//puntero al gato
    QTextEdit * setpasos;
public:
    Mover(Gato * g);
    void mouseDoubleClickEvent( QMouseEvent * event );//evento del doble click
};
#endif // MOVER


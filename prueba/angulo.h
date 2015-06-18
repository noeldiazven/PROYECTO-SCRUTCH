#ifndef ANGULO_H
#define ANGULO_H
#include <QtCore/qglobal.h>
#include<QWidget>
#include "gato.h"
#include "bloques.h"
#include <QMouseEvent>
#include <QTextEdit>
#include <QPainter>
#include <QtGui>
#include <QtCore>
#include <QLabel>
typedef double(dobles);
class Angulo: public Bloques{
private:
    dobles direccion;
    Gato * obj;
    QTextEdit * setpasos;
    dobles pi=3.14159265358979323846;
public:
    Angulo(Gato *g);
    void mouseDoubleClickEvent( QMouseEvent * event );//evento del doble click
    void rotateLabel();
};

#endif // ANGULO_H

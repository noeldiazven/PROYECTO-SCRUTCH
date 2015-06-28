#ifndef BOTONES_H
#define BOTONES_H
#include "tipos.h"
#include <QLabel>

class ventanabotones;

class botones:public QLabel
{
private:
    IDS id;
    entero posx,posy;
    entero width,heigth;
    QPixmap image;
    ventanabotones * parent;
protected:
    void mousePressEvent(QMouseEvent * evento);
public:
    botones(ventanabotones *parent, entero x, entero y, QPixmap i, IDS name);
    void cambiar_imagen();
    inline IDS get_id(){return id;}
};

#endif // BOTONES_H

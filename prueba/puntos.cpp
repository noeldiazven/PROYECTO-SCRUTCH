#include "puntos.h"
#include <qpainter.h>
Puntos::Puntos(QWidget * par){

    second=par;
    QPainter *painterr=new QPainter(second);
    painterr->setRenderHint(QPainter::Antialiasing);
    painterr->setPen(Qt::red);
    painterr->drawLine(100,100,200,200);

}


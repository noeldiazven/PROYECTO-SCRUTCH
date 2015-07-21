#include "puntos.h"
#include <qpainter.h>
Puntos::Puntos(QWidget * par){
    second=par;
    QPainter *painterr=new QPainter(second);
    painterr->setRenderHint(QPainter::Antialiasing);
    painterr->setPen(Qt::red);
    painterr->drawLine(ancho,ancho,largo,largo);

}


#include "botoncomenzar.h"
#include "imagenes.h"

botoncomenzar::botoncomenzar(Gato *g,QLabel * parent)
{
    gato=g;

    posX=400;
    posY=4;
    width=30;
    height=30;

    this->setGeometry(posX,posY,width,height);
    this->setPixmap(bandera_desactivada);
    this->setParent(parent);
}

void botoncomenzar::mousePressEvent(QMouseEvent *evento)
{
    this->setPixmap(bandera_activada);
    gato->correr_vector();
}

void botoncomenzar::mouseReleaseEvent(QMouseEvent *evento)
{
    this->setPixmap(bandera_desactivada);
}

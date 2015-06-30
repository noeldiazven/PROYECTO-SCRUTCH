#include "botoncomenzar.h"
#include "imagenes.h"

botoncomenzar::botoncomenzar(Gato *g,QLabel * parent)
{
    gato=g;
    this->setGeometry(400,4,30,30);
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

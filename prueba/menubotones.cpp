#include "menubotones.h"

menubotones::menubotones(QWidget * parent)
{
    posx=0;
    posy=0;
    width=300;
    heigth=150;
    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#D5D2D2;");
    this->setParent(parent);
}


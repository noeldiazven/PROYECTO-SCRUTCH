#include "ventanabotones.h"

ventanabotones::ventanabotones(QWidget * parent)
{
    posx=0;
    posy=0;
    width=600;
    heigth=400;
    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#B5B3B04;");
    this->setParent(parent);
}


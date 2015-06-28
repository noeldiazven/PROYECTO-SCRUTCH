#include "menubotones.h"
#include <QLabel>
#include "botones.h"
#include "imagenes.h"
#include "ventanabotones.h"

menubotones::menubotones(ventanabotones * p)
{
    parent=p;
    posx=0;
    posy=0;
    width=300;
    heigth=150;
    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#D5D2D2;");
    this->setParent(parent);

    botones * menu_movimiento=new botones(this,0,0,m_movimiento,"m");

    botones * menu_control=new botones(this,150,0,m_control,"c");
}


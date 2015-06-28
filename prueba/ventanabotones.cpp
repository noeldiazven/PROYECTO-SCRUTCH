#include "ventanabotones.h"
#include <algorithm>
#include "botones.h"
#include "imagenes.h"

ventanabotones::ventanabotones(QWidget * parent,Gato * g)
{
    posx=0;
    posy=0;
    width=750;
    heigth=600;
    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#B5B3B04;");
    this->setParent(parent);

    operaciones=new QWidget(this);
    operaciones->setGeometry(300,0,450,600);
    operaciones->setStyleSheet("background-color:#A09D9D;");

    botones * menu_movimiento=new botones(this,0,0,m_movimiento,"m");
    botones * menu_control=new botones(this,150,0,m_control,"c");
}

void ventanabotones::sacar_vectores(QLabel *nuevo)
{
    std::vector<QLabel*>::iterator it;
    it=std::find(botones_movimiento.begin(),botones_movimiento.end(),nuevo);
    if((*it)==nuevo){botones_movimiento.erase(it);}
    it=std::find(botones_control.begin(),botones_control.end(),nuevo);
    if((*it)==nuevo){botones_control.erase(it);}
}

void mostrar (QLabel * i) {  // function:
  i->show();
}
void ocultar(QLabel * i) {  // function:
  i->hide();
}

void ventanabotones::mostrar_botones_movimiento()
{
    std::for_each(botones_movimiento.begin(),botones_movimiento.end(),mostrar);
    std::for_each(botones_control.begin(),botones_control.end(),ocultar);
}

void ventanabotones::mostrar_botones_control()
{
    std::for_each(botones_control.begin(),botones_control.end(),mostrar);
    std::for_each(botones_movimiento.begin(),botones_movimiento.end(),ocultar);
}


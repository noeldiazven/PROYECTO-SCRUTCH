#include "ventanabotones.h"
#include <algorithm>
#include "botones.h"
#include "imagenes.h"
#include"bloques.h"

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
    botones * menu_lapiz =new botones(this,0,35,m_lapiz,"l");
    botones * menu_operadores=new botones(this,150,35,m_operadores,"o");
}

void ventanabotones::erase_todos_botones(Bloques *nuevo)
{
    if(todos_botones.size()!=0){
        std::vector<Bloques*>::iterator it;
        it=std::find(todos_botones.begin(),todos_botones.end(),nuevo);
        if((*it)==nuevo){todos_botones.erase(it);}
    }
}


void ventanabotones::sacar_vectores(QLabel *nuevo)
{
    std::vector<QLabel*>::iterator it;

    it=std::find(botones_movimiento.begin(),botones_movimiento.end(),nuevo);
    if((*it)==nuevo){botones_movimiento.erase(it);}

    it=std::find(botones_control.begin(),botones_control.end(),nuevo);
    if((*it)==nuevo){botones_control.erase(it);}


    it=std::find(botones_lapiz.begin(),botones_lapiz.end(),nuevo);
    if((*it)==nuevo){botones_lapiz.erase(it);}

    it=std::find(botones_operadores.begin(),botones_operadores.end(),nuevo);
    if((*it)==nuevo){botones_operadores.erase(it);}
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
    std::for_each(botones_lapiz.begin(),botones_lapiz.end(),ocultar);
    std::for_each(botones_operadores.begin(),botones_operadores.end(),ocultar);
}

void ventanabotones::mostrar_botones_control()
{
    std::for_each(botones_movimiento.begin(),botones_movimiento.end(),ocultar);
    std::for_each(botones_control.begin(),botones_control.end(),mostrar);
    std::for_each(botones_lapiz.begin(),botones_lapiz.end(),ocultar);
    std::for_each(botones_operadores.begin(),botones_operadores.end(),ocultar);
}

void ventanabotones::mostrar_botones_lapiz(){
    std::for_each(botones_movimiento.begin(),botones_movimiento.end(),ocultar);
    std::for_each(botones_control.begin(),botones_control.end(),ocultar);
    std::for_each(botones_lapiz.begin(),botones_lapiz.end(),mostrar);
    std::for_each(botones_operadores.begin(),botones_operadores.end(),ocultar);
}

void ventanabotones::mostrar_botones_operadores()
{
    std::for_each(botones_movimiento.begin(),botones_movimiento.end(),ocultar);
    std::for_each(botones_control.begin(),botones_control.end(),ocultar);
    std::for_each(botones_operadores.begin(),botones_operadores.end(),mostrar);
    std::for_each(botones_lapiz.begin(),botones_lapiz.end(),ocultar);
}

#include "botones.h"
#include "ventanabotones.h"
#include<QDebug>

void botones::mousePressEvent(QMouseEvent *evento)
{
    //this->cambiar_imagen();
    if(this->get_id()=="m"){
        parent->mostrar_botones_movimiento();
    }
    else if(this->get_id()=="c"){
        parent->mostrar_botones_control();
    }
    else if(this->get_id()=="l"){
        parent->mostrar_botones_lapiz();
    }
    else if(this->get_id()=="o"){
        parent->mostrar_botones_operadores();
    }
}

botones::botones(ventanabotones * p, entero x, entero y, QPixmap i,IDS name)
{
    parent=p;
    image=i;
    id=name;
    posx=x;
    posy=y;
    width=150;
    heigth=30;
    this->setParent(parent);
    this->setGeometry(posx,posy,width,heigth);
    this->setPixmap(image);
}

void botones::cambiar_imagen()
{

}



#include "bloques.h"
#include "ventana.h"
#include <QMouseEvent>
#include <algorithm>
#include <QDebug>

entero Bloques::get_mover_x(){
    return mover_x;
}
entero Bloques::get_mover_y(){
    return mover_y;
}
void Bloques::set_mover_x(entero valor){
    mover_x+=valor;
}
void Bloques::set_mover_y(entero valor){
    mover_y+=valor;
}

void Bloques::mover(entero a, entero b)
{
    set_mover_x(a);
    set_mover_y(b);
    this->setGeometry(get_mover_x(),get_mover_y(),130,35);
    if(siguiente!=nullptr){siguiente->mover(a,b);}
}
void Bloques::mouseMoveEvent(QMouseEvent *evento)
{
    if(evento->buttons()==Qt::LeftButton){

        this->mover(evento->x(),evento->y());
    }
}

void Bloques::mouseReleaseEvent(QMouseEvent *evento)
{
    if(get_mover_x()<300){
        this->setGeometry(x_inicial,y_inicial,130,35);
    }
    else{
        //VERIFICANDO QUE NO SE REPITA EN EL VECTOR
        this->pointer_up_x=mover_x+varianza_up_x;
        this->pointer_up_y=mover_y+varianza_up_y;
        this->pointer_back_x=mover_x+varianza_back_x;
        this->pointer_back_y=mover_y+varianza_back_y;

        std::vector<Bloques*>::iterator it;
        it=std::find(obj->bloques_activos.begin(),obj->bloques_activos.end(),this);

        //verificar si no hay repeticiones
        if((it==obj->bloques_activos.end())||(obj->bloques_activos.size()==0)){
            obj->agregar_vector(this);
            qDebug() <<"agregado"<<"\n";
        }

        obj->verificar(this);
        qDebug() << obj->bloques_activos.size();
    }
}

void Bloques::mouseDoubleClickEvent(QMouseEvent * evento)
{
    this->correr();
}

void Bloques::mousePressEvent(QMouseEvent *evento)
{
    if(this->get_mover_x()<=300){
        this->crear_nuevo();
    }
}


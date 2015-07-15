#include "bloques.h"
#include "ventana.h"
#include <QMouseEvent>
#include <algorithm>
#include <QDebug>

void Bloques::actualizar_puntos(){

    this->pointer_up_x=mover_x+varianza_up_x;
    this->pointer_up_y=mover_y+varianza_up_y;
    this->pointer_back_x=mover_x+varianza_back_x;
    this->pointer_back_y=mover_y+varianza_back_y;

    if(this->get_id()=="for"){
        this->pointer_in_x=mover_x+varianza_in_x; //especiales en los bloques for y if
        this->pointer_in_y=mover_y+varianza_in_y;
    }
}

void Bloques::mover(entero a, entero b)
{
    set_mover_x(a);
    set_mover_y(b);
    this->actualizar_puntos();
    this->setGeometry(get_mover_x(),get_mover_y(),this->get_width(),this->get_height());
    if(siguiente!=nullptr){siguiente->mover(a,b);}
    if(dentro!=nullptr){dentro->mover(a,b);}
    if(siguiente_h!=nullptr){siguiente_h->mover(a,b);}
    if(dentro_h!=nullptr){dentro_h->mover(a,b);}

}

void Bloques::mouseMoveEvent(QMouseEvent *evento)
{
    if(evento->buttons()==Qt::LeftButton){

        this->mover(evento->x(),evento->y());
    }
}
void Bloques::borrar(){
    obj->verificar_vector(this);
    if(this->get_aux()!=nullptr){
        (this->get_aux())->set_size_lista(-1);
        (this->get_aux())->cambiar_medio((this->get_aux())->get_size_lista(),-1);
         if((this->get_aux())->get_size_lista()==0){
             (this->get_aux())->set_dentro(nullptr);
         }
         this->set_aux(nullptr);
    }
    obj->sacar_del_vector(this);
    if(this->dentro!=nullptr){(this->dentro)->borrar();}
    if(this->siguiente!=nullptr){(this->siguiente)->borrar();}
    if(this->dentro_h!=nullptr){(this->dentro_h)->borrar();}
    delete(this);
}
void Bloques::mouseReleaseEvent(QMouseEvent *evento)
{
    if(get_mover_x()<=300){
        qDebug()<<"borrado";
        this->borrar();
    }
    else{
        //VERIFICANDO QUE NO SE REPITA EN EL VECTOR

        std::vector<Bloques*>::iterator it;
        it=std::find(obj->bloques_activos.begin(),obj->bloques_activos.end(),this);

        //verificar si no hay repeticiones
        if((it==obj->bloques_activos.end())||(obj->bloques_activos.size()==0)){
            obj->agregar_vector(this);
            qDebug() <<"agregado"<<"\n";
        }

        obj->verificar(this);
        qDebug() << obj->bloques_activos.size();
        //VERIFICANDO INTERNOS
        it=std::find(obj->bloques_operadores.begin(),obj->bloques_operadores.end(),this);
        if((it==obj->bloques_operadores.end())||(obj->bloques_operadores.size()==0)){
            obj->agregar_vector_h(this);
            qDebug() <<"agregado_h"<<"\n";
        }

        obj->verificar_h(this);
        qDebug() << obj->bloques_operadores.size();
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
        (this->get_ventana())->sacar_vectores(this);
    }
}

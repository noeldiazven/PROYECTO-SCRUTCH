#include "gato.h"
#include "bloques.h"
#include <QDebug>

Gato::Gato(){
    this->setPixmap(QPixmap(":/image/gato.png"));

    posicion_x=130;
    posicion_y=150;
    receptor=0;
    cambiar_posicion_x=0;
    cambiar_posicion_y=0;
    this->setGeometry(get_posicion_x(),get_posicion_y(),80,80);//poniendo en la posicion (x,y) y de tamano (50,50)
}

entero Gato::get_receptor(){
    return receptor;
}

void Gato::set_receptor(entero valor){
    receptor+=valor;
}

entero Gato::get_cambiar_posicion_x(){
    return cambiar_posicion_x;
}
entero Gato::get_cambiar_posicion_y(){
    return cambiar_posicion_y;
}
//-----------------------------------
entero Gato::get_posicion_x(){
    return posicion_x;
}
entero Gato::get_posicion_y(){
    return posicion_y;
}
//--------------------------------------VECTOR
void Gato::agregar_vector(Bloques *nuevo)
{
    bloques_activos.push_back(nuevo);
}
//VERIFICA SI SE ROZAN
inline bool verificar_pos(Bloques * a,Bloques * b){
    if(a!=b){
        if(
         (((a->get_pointer_back_y()+2>=b->get_pointer_up_y())&&(a->get_pointer_back_y()-2<=b->get_pointer_up_y()))&&
         ((a->get_pointer_back_x()+5>=b->get_pointer_up_x())&&(a->get_pointer_back_x()-5<=b->get_pointer_up_x())))
        ){
            a->set_siguiente(b);
            return true;
        }
        else if(
          ((a->get_pointer_up_y()-2<=b->get_pointer_back_y())&&((a->get_pointer_up_y()+2>=b->get_pointer_back_y()))&&
          ((a->get_pointer_up_x()-5<=b->get_pointer_back_x())&&(a->get_pointer_up_x()+5>=b->get_pointer_back_x())))
        ){
            if(a->get_siguiente()!=b){b->set_siguiente(a);}
            else{a->set_siguiente(nullptr);b->set_siguiente(a);}
            return true;
        }
        else{
            if(a->get_siguiente()==b){
                a->set_siguiente(nullptr);
            }
            return false;
        }
        return false;
    }
    return false;
}

//RECORRE LA LISTA
void Gato::verificar(Bloques *nuevo)
{
    std::vector<Bloques*>::iterator it;
    for(it=bloques_activos.begin();it!=bloques_activos.end();it++){
          if(verificar_pos((*it),nuevo)){
              qDebug() << "conectado";
              break;
          }
    }
}
//-----------------------------------
void Gato::set_posicion_x(entero valor){
    posicion_x+=valor;
}
void Gato::set_posicion_y(entero valor){
    posicion_y+=valor;
}
//---------------------------------------
void Gato::set_cambiar_posicion_x(entero valor){
    cambiar_posicion_x = valor;
}

void Gato::set_cambiar_posicion_y(entero valor){
    cambiar_posicion_y = valor;
}

void Gato::mover_gato(entero a, entero b){
    set_posicion_x(a);
    set_posicion_y(b);
    this->setGeometry(get_posicion_x(),get_posicion_y(),80,80);

}

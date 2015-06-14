#include "gato.h"

Gato::Gato(){
    posicion_x=150;
    posicion_y=150;
    cambiar_posicion_x=0;
    cambiar_posicion_y=0;
    this->setGeometry(get_posicion_x(),get_posicion_y(),50,50);//poniendo en la posicion (x,y) y de tamano (50,50)
    this->setStyleSheet("background-color:#9347F7;");//cambiar el color del widget

}
entero Gato::get_cambiar_posicion_x(){
    return cambiar_posicion_x;
}
entero Gato::get_cambiar_posicion_y(){
    return cambiar_posicion_y;
}

entero Gato::get_posicion_x(){
    return posicion_x;
}
entero Gato::get_posicion_y(){
    return posicion_y;
}
void Gato::set_posicion_x(entero valor){
    posicion_x+=valor;
}
void Gato::set_posicion_y(entero valor){
    posicion_y+=valor;
}
void Gato::set_cambiar_posicion_x(entero valor){
    cambiar_posicion_x+=valor;
}

void Gato::set_cambiar_posicion_y(entero valor){
    cambiar_posicion_y+=valor;
}

void Gato::mover_gato(entero a, entero b){
    set_posicion_x(a);
    set_posicion_y(b);
    this->setGeometry(get_posicion_x(),get_posicion_y(),50,50);

}

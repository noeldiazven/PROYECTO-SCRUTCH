#include "gato.h"
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

Gato::Gato(){
    posicion_x=150;
    posicion_y=150;
    this->setGeometry(get_posicion_x(),get_posicion_y(),50,50);//poniendo en la posicion (x,y) y de tamano (50,50)
    this->setStyleSheet("background-color:#9347F7;");//cambiar el color del widget

}

void Gato::mover(entero a)
{
    set_posicion_x(a);
    this->setGeometry(get_posicion_x(),get_posicion_y(),50,50);
}

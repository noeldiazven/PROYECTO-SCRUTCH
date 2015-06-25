#include "sentidohorario.h"
#include "gato.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

UnicaDireccion::UnicaDireccion(Gato*g,QWidget *v){

    siguiente=nullptr;
    obj=g;
    direccion_secundaria=0;
    x_inicial=110;y_inicial=170;
    mover_x=110;
    mover_y=170;
    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;
    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),130,35);
    this->setPixmap(QPixmap(":/image/girar_der.png"));

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(53,3,30,23);
}

void UnicaDireccion::cambiar_direccion(){

    dobles dy=sin((obj->get_receptor()*pi)/180);
    dobles dx=cos((obj->get_receptor()*pi)/180);
    qDebug() << "cos\n"<<dx<<"  seno "<<dy;
    obj->set_cambiar_posicion_y(dy);
    obj->set_cambiar_posicion_x(dx);
}
void UnicaDireccion::crear_nuevo()
{
    UnicaDireccion * n=new UnicaDireccion(obj,ventana);
    n->show();
    qDebug() <<"crear";
}
void UnicaDireccion::correr(){
    direccion_secundaria=setpasos->toPlainText().toInt();

    obj->set_receptor(direccion_secundaria);
    cambiar_direccion();
    if(siguiente!=nullptr){siguiente->correr();}
}

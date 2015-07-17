#include "unicadireccion.h"
#include "girarderecha.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

UnicaDireccion::UnicaDireccion(Gato*g, ventanabotones *v, ventanamostrador *venta){
    ven=venta;
    dx=0;
    dy=0;
    aux=nullptr;
    id="unicaDireccion";
    name="unicaDireccion";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=0;
    mover_x=80;
    mover_y=320;
    width=160;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(block_unica_direccion);

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(125,4,30,23);
}

void UnicaDireccion::abrir(QTextStream &text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<5;i++){
        text >> v;
        if(i==0){direccion=v.toDouble();setpasos->setText(v);}
        if(i==2){this->set_x(v.toDouble());}
        if(i==4){this->set_y(v.toDouble());}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}


QString UnicaDireccion::darValores()
{
    QString res="";
    QString texto=setpasos->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" "+texto+" X "+posiX+" Y "+posiY;
    return res;
}

void UnicaDireccion::crear_nuevo()
{
    UnicaDireccion * n=new UnicaDireccion(obj,ventana,ven);
    n->show();
    ventana->add_botones_movimiento(n);
    QLabel * aux=(*((ventana->botones_movimiento).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}
void UnicaDireccion::rotacion_en_el_plano(){
    dy=sin((obj->get_receptor_unica_direccion()*pi)/180);
    dx=cos((obj->get_receptor_unica_direccion()*pi)/180);


}

void UnicaDireccion::correr(){

    direccion=setpasos->toPlainText().toInt();
    obj->set_Activador3(3);
    obj->rotar_gato_unica_direccion(direccion);
    obj->set_receptor_unica_direccion(-direccion);

    rotacion_en_el_plano();
    qDebug() << "giro";
    obj->set_captor_de_rotacion(direccion);
    obj->set_cambiar_posicion_y(dy);
    obj->set_cambiar_posicion_x(dx);
    if(siguiente!=nullptr){siguiente->correr();}
    ven->pintar_linea();
}

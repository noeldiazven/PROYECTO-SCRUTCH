#include "color.h"
#include "subirlapiz.h"
#include "bajarlapiz.h"
#include "angulo.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>


color::color(Gato*g, ventanabotones *v,ventanamostrador *venta){
    ven=venta;
    dx=0;
    dy=0;
    aux=nullptr;
    id="color";
    name="color";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=0;
    mover_x=80;
    mover_y=240;
    width=143;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(color_lapiz);

    posX_t=108;
    posY_t=4;
    width_t=25;
    height_t=23;

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(posX_t,posY_t,width_t,height_t);
}

QString color::darValores()
{
    QString res="";
    QString texto=setpasos->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    if(texto==""){res=res+name+" "+"0"+" X "+posiX+" Y "+posiY;}
    else{res=res+name+" "+texto+" X "+posiX+" Y "+posiY;}
    return res;
}

void color::abrir(QTextStream &text)
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

void color::crear_nuevo()
{

    color * n=new color(obj,ventana,ven);
    n->show();
    ventana->add_botones_lapiz(n);
    QLabel * aux=(*((ventana->botones_lapiz).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}
void color::correr(){
    ven->pintar_linea();
    direccion=setpasos->toPlainText().toInt();
    obj->set_color(direccion);
    if(siguiente!=nullptr){siguiente->correr();}

}

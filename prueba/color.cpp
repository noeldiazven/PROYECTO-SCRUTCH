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

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(108,4,25,23);
}

QString color::darValores()
{
    QString res="";
    QString texto=setpasos->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" "+texto+" X "+posiX+" Y "+posiY;
    return res;
}

void color::crear_nuevo()
{

    color * n=new color(obj,ventana,ven);
    n->show();
    ventana->add_botones_lapiz(n);
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

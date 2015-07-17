#include "borrar.h"

#include "bajarlapiz.h"
#include "angulo.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>
#include "linea.h"


Borrar::Borrar(Gato*g, ventanabotones *v, ventanamostrador *venta){
    ven=venta;
    dx=0;
    dy=0;
    aux=nullptr;
    id="bajarlapiz";
    name="borrar";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=0;
    mover_x=80;
    mover_y=160;
    width=45;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(borrar_b);
}

QString Borrar::darValores()
{
    QString res="";
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" X "+posiX+" Y "+posiY;
    return res;
}

void Borrar::paintEvent()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);


    painter.setPen(Qt::darkGray);
    painter.drawLine(100,200,300,400);
}

void Borrar::abrir(QTextStream &text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<4;i++){
        text >> v;
        if(i==1){this->set_x(v.toDouble());}
        if(i==3){this->set_y(v.toDouble());}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}

void Borrar::crear_nuevo()
{
    Borrar * n=new Borrar(obj,ventana,ven);
    n->show();
    ventana->add_botones_lapiz(n);
    QLabel * aux=(*((ventana->botones_lapiz).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}
void Borrar::correr(){  
    if(siguiente!=nullptr){siguiente->correr();}
    ven->eliminar_puntos();

}

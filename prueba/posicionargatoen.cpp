#include "posicionargatoen.h"
#include "girarderecha.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

PosicionarGatoEn::PosicionarGatoEn(Gato*g, ventanabotones *v){
    aux=nullptr;
    id="girarDerecha";
    name="Posicion";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=205;
    direccion1=250;
    mover_x=80;
    mover_y=370;
    width=143;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(block_posicion);

    posX_t=58;
    posY_t=4;
    width_t=31;
    height_t=23;

    posX_t1=110;
    posY_t1=4;
    width_t1=31;
    height_t1=23;

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(posX_t,posY_t,width_t,height_t);

    setpasos1=new QTextEdit(this);
    setpasos1->setGeometry(posX_t1,posY_t1,width_t1,height_t1);
}

QString PosicionarGatoEn::darValores()
{
    QString res="";
    QString texto1=setpasos->toPlainText();
    QString texto2=setpasos1->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" "+texto1+" "+texto2+" X "+posiX+" Y "+posiY;
    return res;
}

void PosicionarGatoEn::abrir(QTextStream &text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<6;i++){
        text >> v;
        if(i==0){direccion=v.toDouble();setpasos->setText(v);}
        if(i==1){direccion1=v.toDouble();setpasos1->setText(v);}
        if(i==3){this->set_x(v.toDouble());qDebug()<<v.toInt();}
        if(i==5){this->set_y(v.toDouble());qDebug()<<v.toInt()<<"/"<<v;}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}

void PosicionarGatoEn::crear_nuevo()
{
    PosicionarGatoEn * n=new PosicionarGatoEn(obj,ventana);
    n->show();
    ventana->add_botones_movimiento(n);
    QLabel * aux=(*((ventana->botones_movimiento).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}
void PosicionarGatoEn::correr(){
    direccion=setpasos->toPlainText().toInt();
    direccion1=setpasos1->toPlainText().toInt();
    qDebug() << direccion;
    qDebug() << direccion1;
    obj->set_posicion_xx(direccion);
    obj->set_posicion_yy(direccion1);
    if(obj->get_posicion_x()<=200&&obj->get_posicion_y()<=265&&obj->get_posicion_x()>=-10&&obj->get_posicion_y()>=20){
        obj->mover_gato(obj->get_posicion_x(),obj->get_posicion_y());
    }


    if(siguiente!=nullptr){siguiente->correr();}
}


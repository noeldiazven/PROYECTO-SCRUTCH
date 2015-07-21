#include "division.h"
#include  <QLabel>
#include <QTextEdit>
#include <QDebug>
#include "imagenes.h"
Division::Division(Gato * g,ventanabotones * v  )
{
    aux=nullptr;
    id="operador";
    name="division";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;

    mover_x=80;
    mover_y=290;
    ventana=v;
    width=150;
    height=35;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=24;
    varianza_back_y=32.3;

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);
    this->setPixmap(division);

    posX_t=10;
    posY_t=5;
    width_t=23;
    height_t=23;

    posX_t1=50;
    posY_t1=5;
    width_t1=23;
    height_t1=23;

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(posX_t,posY_t,width_t,height_t);

    setpasos1=new QTextEdit(this);
    setpasos1->setGeometry(posX_t1,posY_t1,width_t1,height_t1);

}

QString Division::darValores()
{
    QString res="";
    QString texto1=setpasos->toPlainText();
    QString texto2=setpasos1->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" "+texto1+" "+texto2+" X "+posiX+" Y "+posiY;
    return res;
}

void Division::abrir(QTextStream &text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<6;i++){
        text >> v;
        if(i==0){valor1=v.toDouble();setpasos->setText(v);}
        if(i==1){valor2=v.toDouble();setpasos1->setText(v);}
        if(i==3){this->set_x(v.toDouble());qDebug()<<v.toInt();}
        if(i==5){this->set_y(v.toDouble());qDebug()<<v.toInt()<<"/"<<v;}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}

void Division::crear_nuevo()
{
    Division * n=new Division(obj,ventana);
    n->show();
    ventana->add_botones_operadores(n);
    QLabel * aux=(*((ventana->botones_operadores).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}
void Division::correr()
{
    valor1=setpasos->toPlainText().toDouble();
    valor2=setpasos1->toPlainText().toDouble();

    valor_num=valor1/valor2;

    qDebug()<<valor_num;

    if(siguiente!=nullptr){siguiente->correr();}
}






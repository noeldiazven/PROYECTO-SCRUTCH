#include "angulo.h"
#include "gato.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

Angulo::Angulo(Gato*g){

    siguiente=nullptr;
    obj=g;
    direccion=0;
    x_inicial=110;y_inicial=80;
    mover_x=110;
    mover_y=80;

    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setGeometry(get_mover_x(),get_mover_y(),130,35);
    this->setPixmap(QPixmap(":/image/girar_izq.png"));

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(53,3,30,23);
}
void Angulo::correr(){
    direccion=setpasos->toPlainText().toInt();

    obj->set_receptor(direccion);

    dobles dy=sin((obj->get_receptor()*pi)/180);
    dobles dx=cos((obj->get_receptor()*pi)/180);

    qDebug() << "cos\n"<<dx<<"  seno "<<dy;

    obj->set_cambiar_posicion_y(-dy);
    obj->set_cambiar_posicion_x(dx);
}


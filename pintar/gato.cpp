#include "gato.h"
#include <QPainter>
animacion_aimagen::animacion_aimagen(QWidget *parent) : QWidget(parent){
    x=40;
    y=40;
}
int animacion_aimagen::getx(){
    return x;
}

int animacion_aimagen::gety(){
    return y;
}

void animacion_aimagen::setx(int x){this->x+=x;}
void animacion_aimagen::sety(int y){this->y+=y;}

void animacion_aimagen::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //para crear la pantalla
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,width()-1,height()-1);
    //para pintar el circulu verde en pantalla otras palabras el gato
    painter.setBrush(Qt::green);
    //posicion del gato en la pantalla
    painter.drawEllipse(getx(),gety(),20,20);
}
void animacion_aimagen::mover(int x,int y){
    setx(x);
    sety(y);
    update();
}
void animacion_aimagen::reiniciar(int valor1, int valor2){
    x=valor1;
    y=valor2;
    update();
}

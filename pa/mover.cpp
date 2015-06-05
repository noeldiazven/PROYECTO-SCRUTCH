#include "mover.h"
#include "gato.h"
#include <QWidget>
#include <QHBoxLayout>
#include  <QLabel>
#include <iostream>
#include <QTextEdit>
//constructor del mover
Mover::Mover(Gato * g)
{
    obj=g;
    pasos=10;
    this->setGeometry(125,30,100,50);
    this->setStyleSheet("background-color:#FA4646;");

    //add text
    QHBoxLayout* layout = new QHBoxLayout(this);
    QLabel * l1=new QLabel();
    l1->setText("Mover");
    l1->setAlignment(Qt::AlignCenter);
    layout->addWidget(l1);

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(70,15,10,10);
    layout->addWidget(setpasos);
}

void Mover::mouseDoubleClickEvent(QMouseEvent *event)
{
    //mover gato al hacer dobleclick
    obj->mover(pasos);
}

#include "gato.h"



Gato::Gato()
{
    x=150;
    y=175;
    this->setGeometry(x,y,50,50);
    this->setStyleSheet("background-color:#9347F7;");

}

void Gato::mover(int a)
{
    x=x+a;
    this->setGeometry(x,y,50,50);
}

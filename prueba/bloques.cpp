#include "bloques.h"
#include <QMouseEvent>
#include <QDebug>

entero Bloques::get_mover_x(){
    return mover_x;
}
entero Bloques::get_mover_y(){
    return mover_y;
}
void Bloques::set_mover_x(entero valor){
    mover_x+=valor;
}
void Bloques::set_mover_y(entero valor){
    mover_y+=valor;
}

void Bloques::mover(entero a, entero b)
{
    set_mover_x(a);
    set_mover_y(b);
    this->setGeometry(get_mover_x(),get_mover_y(),130,35);
}
void Bloques::mouseMoveEvent(QMouseEvent *evento)
{
    if(evento->buttons()==Qt::LeftButton){

        mover(evento->x(),evento->y());
        qDebug() << "funciona\n"<<evento->x()<<","<<evento->y()<<"\n";
    }
}

/*void Bloques::mouseReleaseEvent(QMouseEvent *evento)
{
    if(get_mover_x()<300){
        mover_x=125;
        mover_y=30;
        this->setGeometry(get_mover_x(),get_mover_y(),130,35);
    }
}
*/

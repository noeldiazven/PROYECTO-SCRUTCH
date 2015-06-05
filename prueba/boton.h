#ifndef BOTON
#define BOTON
#include <QWidget>
#include <QMouseEvent>
#include<iostream>
//CLASE PRUEBA
class Boton:public QWidget{
public:
    Boton();
    void mousePressEvent ( QMouseEvent * event )
    {
      //Show x and y coordinate values of mouse cursor here
      //if(event->buttons()==Qt::LeftButton)std::cout<<"PressLeft\nboton";
      //if(event->buttons()==Qt::RightButton)std::cout<<"PressRight\nboton";
    };
    void mouseReleaseEvent(QMouseEvent * event){
        this->setGeometry((event->x()),event->y(),50,50);
    }
};
#endif // BOTON


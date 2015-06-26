#ifndef VETANABOTONES_H
#define VETANABOTONES_H
#include <QWidget>
#include"gato.h"
class ventanabotones:public QWidget
{
private:
    entero posx,posy;
    entero width,heigth;
public:
    ventanabotones(QWidget * parent);
    inline void set_posx(entero x){posx=x;}
    inline void set_posy(entero y){posy=y;}
    inline entero get_posx(){return posx;}
    inline entero get_posy(){return posy;}
    inline void set_width(entero w){width=w;}
    inline void set_heigth(entero h){heigth=h;}
    inline entero get_width(){return width;}
    inline entero get_heigth(){return heigth;}
};

#endif // VETANABOTONES_H

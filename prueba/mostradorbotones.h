#ifndef MOSTRADORBOTONES_H
#define MOSTRADORBOTONES_H
#include<QWidget>
#include "gato.h"

class mostradorbotones:public QWidget
{
    entero posx,posy;
    entero width,heigth;

public:
    mostradorbotones(QWidget * parent, Gato *g);
    inline void set_posx(entero x){posx=x;}
    inline void set_posy(entero y){posy=y;}
    inline entero get_posx(){return posx;}
    inline entero get_posy(){return posy;}
    inline void set_width(entero w){width=w;}
    inline void set_heigth(entero h){heigth=h;}
    inline entero get_width(){return width;}
    inline entero get_heigth(){return heigth;}
};

#endif // MOSTRADORBOTONES_H

#ifndef VENTANAOPERACIONES_H
#define VENTANAOPERACIONES_H
#include <QWidget>
#include "gato.h"

class ventanamostrador:public QWidget
{
    entero posx,posy;
    entero width,heigth;
    QLabel * comenzar;
    Gato * cat;
public:
    ventanamostrador(QWidget * p);
    inline void set_posx(entero x){posx=x;}
    inline void set_posy(entero y){posy=y;}
    inline entero get_posx(){return posx;}
    inline entero get_posy(){return posy;}
    inline void set_width(entero w){width=w;}
    inline void set_heigth(entero h){heigth=h;}
    inline entero get_width(){return width;}
    inline entero get_heigth(){return heigth;}
    inline Gato * get_cat(){return cat;}
};

#endif // VENTANAOPERACIONES_H

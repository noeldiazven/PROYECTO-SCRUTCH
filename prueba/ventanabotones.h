#ifndef VETANABOTONES_H
#define VETANABOTONES_H
#include <QWidget>
#include <vector>
#include"gato.h"
#include "tipos.h"

class ventanabotones:public QWidget
{
private:
    entero posx,posy;
    entero width,heigth;
    QWidget * operaciones;
    std::vector<QLabel*> botones_movimiento;
    std::vector<QLabel*> botones_control;

public:
    ventanabotones(QWidget * parent, Gato *g);
    inline void set_posx(entero x){posx=x;}
    inline void set_posy(entero y){posy=y;}
    inline entero get_posx(){return posx;}
    inline entero get_posy(){return posy;}
    inline void set_width(entero w){width=w;}
    inline void set_heigth(entero h){heigth=h;}
    inline entero get_width(){return width;}
    inline entero get_heigth(){return heigth;}
    inline void add_botones_movimiento(QLabel * nuevo){botones_movimiento.push_back(nuevo);}
    inline void add_botones_control(QLabel * nuevo){botones_control.push_back(nuevo);}
    void sacar_vectores(QLabel * nuevo);
    void mostrar_botones_movimiento();
    void mostrar_botones_control();
};

#endif // VETANABOTONES_H

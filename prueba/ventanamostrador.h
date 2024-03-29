#ifndef VENTANAOPERACIONES_H
#define VENTANAOPERACIONES_H
#include <QWidget>
#include "tipos.h"
#include "gato.h"
#include "botoncomenzar.h"
#include "botonguardar.h"
#include "botonabrir.h"
#include <vector>
#include <QLabel>
#include "punto.h"
#include "puntos.h"
#include "ventanabotones.h"

class ventanamostrador:public QWidget{
private:
    entero posx,posy;
    entero width,heigth;
    QLabel * comenzar;
    QLabel *puntito;
    botoncomenzar * bandera;
    botonguardar * guardar;
    botonabrir * abrir;
    Gato * cat;
    Punto *pt;
    Puntos *pts;
    QWidget *nuevo;
    ventanabotones * b;//puntero a la ventana botones

    entero pos_x_punto;
    entero pos_y_punto;

    tipo_entero activador;
    entero posInicialX;
    entero posInicialY;
    tipo_entero comparador;
    entero pi;
    entero acumulador;
    entero acumulador1;

    entero anteriorX;
    entero anteriorY;
    entero sumador_de_angulo;

    std::vector<QLabel*>lapiz;
    std::vector<QLabel*>::iterator B;

public:
    ventanamostrador(QWidget * p, ventanabotones *botones);
    inline void add_lapiz(QLabel* nuevo){lapiz.push_back(nuevo);}

    inline void set_posx(entero x){posx=x;}
    inline void set_posy(entero y){posy=y;}
    inline entero get_posx(){return posx;}
    inline entero get_posy(){return posy;}
    inline void set_width(entero w){width=w;}
    inline void set_heigth(entero h){heigth=h;}
    inline entero get_width(){return width;}
    inline entero get_heigth(){return heigth;}
    inline Gato * get_cat(){return cat;}
    inline QWidget * get_b(){return b;}

    QLabel *get_linea(){return puntito;}
    void paintEvent(QPaintEvent*);
    void pintar_linea();
    void mostrar_puntitos();
    void rotacion_en_el_plano();
    void eliminar_puntos();


   // inline Linea*get_linea(){return line;}
};


#endif // VENTANAOPERACIONES_H

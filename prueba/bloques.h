#ifndef BLOQUES
#define BLOQUES
#include <QLabel>
#include <QTextEdit>
#include "tipos.h"
#include "ventanabotones.h"
#include "ventanamostrador.h"
#include "ayuda.h"


class Bloques:public QLabel{
protected:
    IDS id;
    ventanabotones * ventana; //ventana donde se crean los bloques
    Punto *punto;
    ventanamostrador *ven;
    Gato * obj; //objecto que se modificara
    Bloques * siguiente; //puntero que apunta al bloque de abajo
    Bloques * dentro;
    Bloques * aux;
    QTextEdit * setpasos; //variable que guarda el valor insertado del usuario
    QTextEdit * setpasos1;

    Bloques * aux_h=nullptr;
    Bloques * dentro_h=nullptr;
    Bloques * siguiente_h=nullptr;
    bool valor;
    float valor_num=0;
    //Posiciones x,y
    entero mover_x;entero mover_y;
    entero width;entero height; //the block's size

    entero varianza_up_x,varianza_up_y;     //varianza de los puntos de enlace
    entero varianza_back_x,varianza_back_y; //arriba y abajo
    entero varianza_in_x;entero varianza_in_y;
    entero pointer_up_x,pointer_up_y;     //x,y del punto de enlaze arriba
    entero pointer_back_x,pointer_back_y; //x,y del punto de enlaze de abajo
    entero pointer_in_x,pointer_in_y;

    virtual void crear_nuevo(){}
    void mover(entero a, entero b);

    //EVENTOS DEL MOUSE
    void mouseMoveEvent(QMouseEvent * evento);
    void mouseReleaseEvent(QMouseEvent * evento);
    void mouseDoubleClickEvent(QMouseEvent * evento);//evento del doble click
    void mousePressEvent(QMouseEvent * evento);

public:

    inline bool get_valor(){return valor;}
    inline float get_valor_num(){return valor_num;}

    virtual void correr(){}
    virtual void cambiar_medio(entero x,int y){}
    virtual entero get_size_lista(){}
    virtual void set_size_lista(int x){}



    //alargamiento horizontal
    virtual void cambiar_medio_a(entero x,int y){}
    virtual entero get_size_lista_h(){}
    virtual void set_size_lista_h(int x){}
    inline void set_aux_h(Bloques * nuevo){aux_h=nuevo;}
    inline Bloques * get_aux_h(){return aux_h;}
    inline void set_dentro_h(Bloques * nuevo){dentro_h=nuevo;}
    inline Bloques * get_dentro_h(){return dentro_h;}
    inline void set_siguiente_h(Bloques * nuevo){siguiente_h=nuevo;}
    inline Bloques * get_siguiente_h(){return siguiente_h;}

    inline void set_aux(Bloques * nuevo){aux=nuevo;}
    inline Bloques * get_aux(){return aux;}

    inline void set_siguiente(Bloques * nuevo){siguiente=nuevo;}
    inline Bloques * get_siguiente(){return siguiente;}

    inline void set_dentro(Bloques * nuevo){dentro=nuevo;}
    inline Bloques * get_dentro(){return dentro;}

    inline void set_ventana(ventanabotones * nuevo){ventana=nuevo;}
    inline ventanabotones * get_ventana(){return ventana;}

    inline entero get_mover_x(){return mover_x;}
    inline entero get_mover_y(){return mover_y;}
    inline entero get_width(){return width;}
    inline entero get_height(){return height;}
    inline IDS get_id(){return id;}

    inline void set_mover_x(entero valor){mover_x+=valor;}
    inline void set_mover_y(entero valor){mover_y+=valor;}

    inline entero get_pointer_back_x(){return pointer_back_x;}
    inline entero get_pointer_back_y(){return pointer_back_y;}
    inline entero get_pointer_up_x(){return pointer_up_x;}
    inline entero get_pointer_up_y(){return pointer_up_y;}
    inline entero get_pointer_in_x(){return pointer_in_x;}
    inline entero get_pointer_in_y(){return pointer_in_y;}
    inline entero get_varianza_up_x(){return varianza_up_x;}
    inline entero get_varianza_up_y(){return varianza_up_y;}

    void borrar();
};
#endif // BLOQUES

/******************************************************************************************************
*****FALTA SEPARARLO MAS EN CLASES Y SER MAS ORDENADOS DEPENDIENDO DE QUE METODO NECESITE CADA CLASE***
*****FALTA CREAR DEMAS BOTONES SERAN ALREDEDOR DE 15 O UN POCO MAS XD**********************************
*******************************************************************************************************/

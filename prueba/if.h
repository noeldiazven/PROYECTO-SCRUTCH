#ifndef IF_H
#define IF_H
#include "bloques.h"
#include "tipos.h"
#include <QWidget>


class IF:public Bloques
{
protected:
    entero iteraciones;
public:
    IF(Gato * g,ventanabotones * v);
    QLabel * arriba_izq;
    QLabel * arriba_med;
    QLabel * arriba_der;
    QLabel * abajo;
    QLabel * medio;
    entero lista;
    entero lista_arriba;
    void cambiar_medio(entero x, int y);
    void cambiar_arriba(entero x, int y);
    inline entero get_size_lista(){return lista;}
    inline void set_size_lista(int x){lista+=x;}
    void crear_nuevo();
};

#endif // IF_H

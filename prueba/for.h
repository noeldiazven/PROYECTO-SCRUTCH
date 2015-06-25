#ifndef FOR_H
#define FOR_H
#include "bloques.h"
#include "gato.h"
#include <QWidget>

class For:public Bloques
{
protected:
    entero iteraciones;
public:
    For(Gato * g,QWidget * v);
    QLabel * arriba;
    QLabel * abajo;
    QLabel * medio;
    entero lista;
    void correr();
    void crear_nuevo();
    void cambiar_medio(int x);
    entero get_size_lista();
    void set_size_lista(int x);
};

#endif // FOR_H

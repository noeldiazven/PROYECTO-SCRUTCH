#ifndef GATO
#define GATO
#include<QWidget>
typedef double(entero);
class Gato:public QWidget{
private:
    entero posicion_x;
    entero posicion_y;
    entero cambiar_posicion_x;
    entero cambiar_posicion_y;
public:
    Gato();
    entero get_posicion_x();
    entero get_posicion_y();

    entero get_cambiar_posicion_x();
    entero get_cambiar_posicion_y();

    void set_posicion_x(entero);
    void set_cambiar_posicion_x(entero);
    void set_cambiar_posicion_y(entero);
    void set_posicion_y(entero);
    void mover_gato(entero a,entero b);
};

#endif // GATO


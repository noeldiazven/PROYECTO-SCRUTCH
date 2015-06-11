#ifndef GATO
#define GATO
#include<QWidget>
typedef int(entero);
class Gato:public QWidget{
private:
    entero posicion_x;
    entero posicion_y;
public:
    Gato();
    entero get_posicion_x();
    entero get_posicion_y();
    void set_posicion_x(entero);
    void set_posicion_y(entero);
    void mover(entero a);
};

#endif // GATO


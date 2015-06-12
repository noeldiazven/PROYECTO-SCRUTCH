#ifndef VENTANA
#define VENTANA
#include "gato.h"
#include "mover.h"
#include "angulo.h"
#include<QMainWindow>

class ventana:public QMainWindow{
protected:
    QWidget * Botones;
    QWidget * mostrador;
    QWidget * operaciones;
    Gato * cat;
    Mover * botonmover;
    Angulo * botonangulo;
public:
    ventana();
    QWidget * setBotones(){return Botones;}
    QWidget * setmostador(){return mostrador;}
};
#endif // VENTANA


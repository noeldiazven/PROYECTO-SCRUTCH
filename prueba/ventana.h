#ifndef VENTANA
#define VENTANA
#include "gato.h"
#include "mover.h"
#include "angulo.h"
#include<QMainWindow>

class ventana:public QMainWindow{
private:
QSize s;
protected:
    QWidget * Botones;
    QWidget * mostrador;
    QWidget * operaciones;
    Gato * cat;
    Mover * botonmover;
    Angulo * botonangulo;
public:
    ventana();
    QWidget * getbotonmover(){return botonmover;}
    QWidget * getbotonangulo(){return botonangulo;}
    QWidget * setBotones(){return Botones;}
    QWidget * setmostador(){return mostrador;}
};
#endif // VENTANA


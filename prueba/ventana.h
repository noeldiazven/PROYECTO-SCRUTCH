#ifndef VENTANA
#define VENTANA
#include "gato.h"
#include "mover.h"
#include "angulo.h"
#include "inicio.h"
#include "bloques.h"
#include "sentidohorario.h"
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
    inicio * botoninicio;
    UnicaDireccion* botonDireccion;

public:
    ventana();
    QWidget * getbotonmover(){return botonmover;}
    QWidget * getbotonangulo(){return botonangulo;}
    QWidget * getBotones(){return Botones;}
    QWidget * setmostador(){return mostrador;}
};
#endif // VENTANA


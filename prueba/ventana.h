#ifndef VENTANA
#define VENTANA
#include "gato.h"
#include "mover.h"
#include "angulo.h"
#include "inicio.h"
#include "bloques.h"
#include "for.h"
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
    For * botonfor;

public:
    ventana();
    QWidget * getbotonmover(){return botonmover;}
    QWidget * getbotonangulo(){return botonangulo;}
    QWidget * getBotones(){return Botones;}
    QWidget * setmostador(){return mostrador;}
};
#endif // VENTANA

/******************************************************************************************************
*****FALTA CREAR LAS CLASES DE CADA ESPACIO DE LA VENTANA************(BOTONES,MOSTRADOR,OPERACIONES)***
*****FALTA DIVIDIR LA PARTE DE BOTONES PARA QUE PUEDA MOSTRR MAS DE UN WIDGET *************************
*******************************************************************************************************/

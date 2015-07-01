#ifndef VENTANA
#define VENTANA
#include "gato.h"
#include "mover.h"
#include "angulo.h"
#include "inicio.h"
#include "for.h"
#include "if.h"
#include "ventanabotones.h"
#include "ventanamostrador.h"
#include "girarderecha.h"
#include "unicadireccion.h"
#include "posicionargatoen.h"
#include "rebote.h"
#include<QMainWindow>

class ventana:public QMainWindow{
private:
QSize s;
protected:
    ventanabotones * Botones;
    ventanamostrador * mostrador;
    Mover * botonmover;
    Angulo * botonangulo;
    inicio * botoninicio;
    For * botonfor;
    IF * botonif;
    GirarDerecha *botongirarderecha;
    UnicaDireccion *boton_unica_direccion;
    PosicionarGatoEn *boton_posicionar;
    Rebote *botonrebotar;



public:
    ventana();
    inline QWidget * getbotonmover(){return botonmover;}
    inline QWidget * getbotonangulo(){return botonangulo;}
    inline QWidget * getBotones(){return Botones;}
    inline QWidget * setmostador(){return mostrador;}
};
#endif // VENTANA

/******************************************************************************************************
*****FALTA CREAR LAS CLASES DE CADA ESPACIO DE LA VENTANA************(MOSTRADOR,OPERACIONES)***********
*****FALTA DIVIDIR LA PARTE DE BOTONES PARA QUE PUEDA MOSTRAR MAS DE UN WIDGET ************************
*******************************************************************************************************/

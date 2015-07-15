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
#include "bajarlapiz.h"
#include "lineas.h"
#include<QMainWindow>
#include "borrar.h"
#include "subirlapiz.h"
#include "color.h"
#include "Igual.h"
#include "mayor_menor.h"
#include "menor_mayor.h"
#include "suma.h"
#include "resta.h"
#include "multiplicacion.h"
#include "division.h"

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
    Borrar *botonborrar;
    Linea *line;
    color *botoncolor;
    Igual * botonigual;
    Mayor_menor * botonmayor_menor;
    Menor_mayor * botonmenor_mayor;
    Suma * boton_suma;
    Resta * boton_resta;
    Division * boton_division;
    Multiplicacion * boton_multiplicacion;

    //-----------------
    BajarLapiz *boton_bajar;
    subirlapiz *botonsubir;




public:
    ventana();
    inline QWidget * getbotonmover(){return botonmover;}
    inline QWidget * getbotonangulo(){return botonangulo;}
    inline QWidget * getBotones(){return Botones;}
    inline QWidget * setmostador(){return mostrador;}
};
#endif // VENTANA


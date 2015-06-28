#ifndef GATO
#define GATO
#include <QLabel>
#include <QMatrix>
#include "tipos.h"

class Bloques;

class Gato:public QLabel{
private:
    QWidget * parent;
    QPixmap img;

    entero width;
    entero heigth;

    entero posicion_x;
    entero posicion_y;

    entero cambiar_posicion_x;
    entero cambiar_posicion_y;

    tipo_entero rotar;

    entero receptor;

public:
    Gato(QWidget *par);
    void rotar_gato(tipo_entero giro);
    inline QWidget * get_parent(){return parent;}
    inline entero get_posicion_x(){return posicion_x;}
    inline entero get_posicion_y(){return posicion_y;}
    inline entero get_receptor(){return receptor;}
    inline void set_receptor(entero valor){receptor+=valor;}

    inline entero get_cambiar_posicion_x(){return cambiar_posicion_x;}
    inline entero get_cambiar_posicion_y(){return cambiar_posicion_y;}

    inline void set_posicion_y(entero valor){posicion_y+=valor;}
    inline void set_posicion_x(entero valor){posicion_x+=valor;}

    inline void set_cambiar_posicion_x(entero valor){cambiar_posicion_x = valor;}
    inline void set_cambiar_posicion_y(entero valor){cambiar_posicion_y = valor;}

    void mover_gato(entero a,entero b);

    std::vector <Bloques*> bloques_activos;
    void agregar_vector(Bloques * nuevo);
    void sacar_del_vector(Bloques * nuevo);
    void verificar(Bloques * nuevo);
};

#endif // GATO

/***************************************************************************************************
*****FALTA IMPLEMENTAR LOS EVENTOS DEL MOUSE PARA PODER MOVER EL GATO CON EL RATON SIN NECESIDAD DE*
*****ALGUN BOTON,ADEMAS UN POCO DE ORDEN RESPECTO A SU .CPP*****************************************
***************************************************************************************************/

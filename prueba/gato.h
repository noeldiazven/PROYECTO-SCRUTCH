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

    entero copia_x;
    entero copia_y;

    entero cambiar_posicion_x;
    entero cambiar_posicion_y;

    tipo_entero rotar;

    entero receptor;
    entero unico_receptor;

    tipo_entero activador;
    tipo_entero activador_De_punto;
    tipo_entero controlador_De_lapiz;

    tipo_entero captor_de_mover;

    entero captor_de_rotacion;
    entero color;

    entero activador3;
    entero activador2;
    entero sumador;
    entero borra;

public:

    Gato(QWidget *par);
    entero get_borra(){return borra;}
    void set_borra(entero valor){borra==valor;}
    entero get_color(){return color;}
    void set_color(int valor){color=valor;}
    entero get_sumador(){return sumador;}
    void set_sumador(tipo_entero valor){sumador=valor;}

    entero get_captor_de_rotacion(){return captor_de_rotacion;}

    entero get_activador3(){return activador3;}
    entero set_Activador3(entero valor){activador3=valor;}

    entero get_activador2(){return activador2;}
    entero set_Activador2(entero valor){activador2=valor;}

    void set_captor_de_rotacion(entero valor){captor_de_rotacion=valor;}

    tipo_entero get_captor_De_mover(){return captor_de_mover;}
    void set_captor_de_mover(tipo_entero valor){captor_de_mover=valor;}

    void set_controlador_de_lapiz(tipo_entero valor){controlador_De_lapiz=valor;}
    tipo_entero get_controlador_de_lapiz(){return controlador_De_lapiz;}

    void rotar_gato(tipo_entero giro);
    inline QWidget * get_parent(){return parent;}
    inline entero set_activador(tipo_entero valor){activador=valor;}

    inline entero get_posicion_x(){return posicion_x;}
    inline entero get_posicion_y(){return posicion_y;}

    inline entero get_copia_x(){return copia_x;}
    inline entero get_copia_y(){return copia_y;}

    inline void set_copia_x(){copia_x=posicion_x;}
    inline void set_copia_y(){copia_y=posicion_y;}

    inline tipo_entero get_activador(){return activador;}
    inline entero get_receptor(){return receptor;}
    inline entero get_receptor_unica_direccion(){return unico_receptor;}
    inline entero get_activador_de_punto(){return activador_De_punto;}
    inline void set_receptor(entero valor){receptor+=valor;}
    inline void set_receptor_unica_direccion(entero valor){unico_receptor=valor;}

    inline entero get_cambiar_posicion_x(){return cambiar_posicion_x;}
    inline entero get_cambiar_posicion_y(){return cambiar_posicion_y;}

    inline void set_posicion_y(entero valor){posicion_y+=valor;}
    inline void set_posicion_x(entero valor){posicion_x+=valor;}

    inline void set_posicion_y_ayuda(entero valor){posicion_y-=valor;}

    inline void set_posicion_yy(entero valor){posicion_y=valor;}
    inline void set_posicion_xx(entero valor){posicion_x=valor;}

    inline void set_cambiar_posicion_x(entero valor){cambiar_posicion_x = valor;}
    inline void set_cambiar_posicion_y(entero valor){cambiar_posicion_y = valor;}

    void mover_gato(entero a,entero b);
    void rotar_gato_unica_direccion(tipo_entero valor);

    std::vector <Bloques*> bloques_activos;
    void agregar_vector(Bloques * nuevo);
    void sacar_del_vector(Bloques * nuevo);
    void verificar(Bloques * nuevo);
    void verificar_vector(Bloques * nuevo);
    void correr_vector();

    std::vector <Bloques*> bloques_operadores;
    void agregar_vector_h(Bloques * nuevo);
    void sacar_del_vector_h(Bloques * nuevo);
    void verificar_h(Bloques * nuevo);
    void correr_vector_h();

};

#endif // GATO

/***************************************************************************************************
*****FALTA IMPLEMENTAR LOS EVENTOS DEL MOUSE PARA PODER MOVER EL GATO CON EL RATON SIN NECESIDAD DE*
*****ALGUN BOTON,ADEMAS UN POCO DE ORDEN RESPECTO A SU .CPP*****************************************
***************************************************************************************************/

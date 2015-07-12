#ifndef AYUDA_H
#define AYUDA_H
#include <QWidget>
#include <vector>
#include"gato.h"
#include "tipos.h"
#include <QtCore/qglobal.h>
#include <QLabel>
#include <QMatrix>
#include "tipos.h"
#include "bloques.h"
#include "tipos.h"
class Ayuda:public QLabel{
private:
    QWidget * parent;
    QPixmap img;
    QWidget *operacioness;


    entero width;
    entero heigth;

    entero posicion_x;
    entero posicion_y;

    entero cambiar_posicion_x;
    entero cambiar_posicion_y;

    tipo_entero rotar;

    entero receptor;
    entero unico_receptor;

    tipo_entero activador;
    Gato*obj;
    entero contador;

public:
    Ayuda(QWidget *par, Gato*gatito);
    entero get_x(){return obj->get_posicion_x();}
    void pintar_punto();
    void set_contador(entero c){contador=c;}
    entero get_contador(){return contador;}
    QPixmap get_img(){return img;}

};

#endif // AYUDA_H

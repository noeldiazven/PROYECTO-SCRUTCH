#ifndef LINEAS_H
#define LINEAS_H

#include <QLabel>
#include <QMatrix>
#include "tipos.h"
#include <QPoint>
#include <QtCore>
#include <QPainter>
#include <QMouseEvent>

class lineas : public QWidget

{

    QPoint m_start_point;

    QPoint m_end_point;



    void mousePressEvent(QMouseEvent* event)

    {

        if (hasMouseTracking())

        {

            setMouseTracking(false);

        }

        else

        {

            m_start_point = m_end_point = event->pos();

            setMouseTracking(true);

            update();

        }

    }



    void mouseMoveEvent(QMouseEvent* event)

    {

        m_end_point = event->pos();

        update();

    }



    void paintEvent(QPaintEvent*)

    {

        QPainter(this).drawLine(m_start_point, m_end_point);

    }

};


/*
class Bloques;
class lineas:public QLabel{
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
    entero unico_receptor;

    tipo_entero activador;

public:
    void paintEvent(QPaintEvent*);

    lineas(QWidget *par);
    void rotar_gato(tipo_entero giro);
    inline QWidget * get_parent(){return parent;}
    inline entero set_activador(tipo_entero valor){activador=valor;}

    inline entero get_posicion_x(){return posicion_x;}
    inline entero get_posicion_y(){return posicion_y;}

    inline tipo_entero get_activador(){return activador;}
    inline entero get_receptor(){return receptor;}
    inline entero get_receptor_unica_direccion(){return unico_receptor;}

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

};*/
#endif // LINEAS_H

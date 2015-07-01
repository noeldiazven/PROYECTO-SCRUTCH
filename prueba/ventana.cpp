#include<QMainWindow>
#include "ventana.h"
#include "imagenes.h"
#include <QLabel>

ventana::ventana()
{
    this->setWindowTitle(QString::fromUtf8("SCRUTCH"));
    this->setWindowIcon(icono);
    this->resize(1200,600);
    this->setMinimumSize(QSize(1200,600));
    this->setMaximumSize(QSize(1200,600));

    mostrador=new ventanamostrador(this);

    Botones=new ventanabotones(this,mostrador->get_cat());


    //creando botones

    //agregandolo al boton mover
    botonmover=new Mover(mostrador->get_cat(),Botones);
    Botones->add_botones_movimiento(botonmover);

    //agregandolo al boton angulo
    botonangulo=new Angulo(mostrador->get_cat(),Botones);
    Botones->add_botones_movimiento(botonangulo);

    //agregandolo al boton girar derecha
    botongirarderecha = new GirarDerecha(mostrador->get_cat(),Botones);
    Botones->add_botones_movimiento(botongirarderecha);
    //agregando boton unica direccion
    boton_unica_direccion =new UnicaDireccion(mostrador->get_cat(),Botones);
    Botones->add_botones_movimiento(boton_unica_direccion);

    //agregando boton posicionar
    boton_posicionar =new PosicionarGatoEn(mostrador->get_cat(),Botones);
    Botones->add_botones_movimiento(boton_posicionar);

    //agregando el boton correr
    botoninicio=new inicio(mostrador->get_cat(),Botones);
    Botones->add_botones_control(botoninicio);
    //agregando boton rebotar
    botonrebotar =new Rebote(mostrador->get_cat(),Botones);
    Botones->add_botones_movimiento(botonrebotar);

    //agregando el boton for
    botonfor=new For(mostrador->get_cat(),Botones);
    Botones->add_botones_control(botonfor);

    //agregando el boton if
    botonif=new IF(mostrador->get_cat(),Botones);
    Botones->add_botones_control(botonif);

    Botones->mostrar_botones_movimiento();

}

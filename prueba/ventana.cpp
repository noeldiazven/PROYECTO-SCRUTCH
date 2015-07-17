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

    Botones=new ventanabotones(this,mostrador->get_cat());

    mostrador=new ventanamostrador(this,Botones);

    //creando botones
    //_________________botones_lapiz___________

    boton_bajar =new BajarLapiz(mostrador->get_cat(),Botones);
    Botones->add_botones_lapiz(boton_bajar);
    Botones->add_todos_botones(boton_bajar);

    botonborrar =new Borrar(mostrador->get_cat(),Botones,mostrador);
    Botones->add_botones_lapiz(botonborrar);
    Botones->add_todos_botones(botonborrar);

    botonsubir =new subirlapiz(mostrador->get_cat(),Botones);
    Botones->add_botones_lapiz(botonsubir);
    Botones->add_todos_botones(botonsubir);

    botoncolor =new color(mostrador->get_cat(),Botones,mostrador);
    Botones->add_botones_lapiz(botoncolor);
    Botones->add_todos_botones(botoncolor);

    //agregandolo al boton mover
    botonmover=new Mover(mostrador->get_cat(),Botones,mostrador);
    Botones->add_botones_movimiento(botonmover);
    Botones->add_todos_botones(botonmover);

    //agregandolo al boton angulo
    botonangulo=new Angulo(mostrador->get_cat(),Botones,mostrador);
    Botones->add_botones_movimiento(botonangulo);
    Botones->add_todos_botones(botonangulo);

    //agregandolo al boton girar derecha
    botongirarderecha = new GirarDerecha(mostrador->get_cat(),Botones,mostrador);
    Botones->add_botones_movimiento(botongirarderecha);
    Botones->add_todos_botones(botongirarderecha);

    //agregando boton unica direccion
    boton_unica_direccion =new UnicaDireccion(mostrador->get_cat(),Botones,mostrador);
    Botones->add_botones_movimiento(boton_unica_direccion);
    Botones->add_todos_botones(boton_unica_direccion);

    //agregando boton posicionar
    boton_posicionar =new PosicionarGatoEn(mostrador->get_cat(),Botones);
    Botones->add_botones_movimiento(boton_posicionar);
    Botones->add_todos_botones(boton_posicionar);

    //agregando el boton correr
    botoninicio=new inicio(mostrador->get_cat(),Botones);
    Botones->add_botones_control(botoninicio);
    Botones->add_todos_botones(botoninicio);

    //agregando boton rebotar
    botonrebotar =new Rebote(mostrador->get_cat(),Botones);
    Botones->add_botones_movimiento(botonrebotar);
    Botones->add_todos_botones(botonrebotar);

    //agregando el boton for
    botonfor=new For(mostrador->get_cat(),Botones);
    Botones->add_botones_control(botonfor);
    Botones->add_todos_botones(botonfor);

    //agregando el boton if
    botonif=new IF(mostrador->get_cat(),Botones);
    Botones->add_botones_control(botonif);
    Botones->add_todos_botones(botonif);

    //A=new Ayuda(mostrador->get_cat(),Botones);
    //Botones->add_botones_lapiz(A);


    //agregando el boton ==
    botonigual=new Igual(mostrador->get_cat(),Botones);
    Botones->add_botones_operadores(botonigual);
    Botones->add_todos_botones(botonigual);

    //agregando el boton >
    botonmayor_menor=new Mayor_menor(mostrador->get_cat(),Botones);
    Botones->add_botones_operadores(botonmayor_menor);
    Botones->add_todos_botones(botonmayor_menor);

    //agregando el boton <
    botonmenor_mayor=new Menor_mayor(mostrador->get_cat(),Botones);
    Botones->add_botones_operadores(botonmenor_mayor);
    Botones->add_todos_botones(botonmenor_mayor);

    //agregando el boton +
    boton_suma=new Suma(mostrador->get_cat(),Botones);
    Botones->add_botones_operadores(boton_suma);
    Botones->add_todos_botones(boton_suma);

    //agregando el boton -
    boton_resta=new Resta(mostrador->get_cat(),Botones);
    Botones->add_botones_operadores(boton_resta);
    Botones->add_todos_botones(boton_resta);

    //agregando el boton /
    boton_division=new Division(mostrador->get_cat(),Botones);
    Botones->add_botones_operadores(boton_division);
    Botones->add_todos_botones(boton_division);

    //agregando el boton *
    boton_multiplicacion=new Multiplicacion(mostrador->get_cat(),Botones);
    Botones->add_botones_operadores(boton_multiplicacion);
    Botones->add_todos_botones(boton_multiplicacion);



    Botones->mostrar_botones_movimiento();

}

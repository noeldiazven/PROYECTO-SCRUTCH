#include<QMainWindow>
#include "ventana.h"


ventana::ventana()
{
    this->setWindowTitle(QString::fromUtf8("SCRUTCH"));
    this->resize(900, 400);

    //creando el panel de botones
    Botones=new QWidget(this);
    Botones->setGeometry(0,0,600,400);
    Botones->setStyleSheet("background-color:#B5B3B04;");

    //creando el panel del gato
    mostrador=new QWidget(this);
    mostrador->setGeometry(600,0,300,400);
    mostrador->setStyleSheet("background-color:#FFFFFF;");

    //crenado panel de operaciones
    operaciones=new QWidget(Botones);
    operaciones->setGeometry(300,0,300,400);
    operaciones->setStyleSheet("background-color:#79E592;");

    //creando el gato
    cat=new Gato();
    cat->setParent(mostrador);

    //creando botones

    //agregandolo al boton mover
    botonmover=new Mover(cat);
    botonmover->setParent(Botones);

    //agregandolo al boton angulo
    botonangulo=new Angulo(cat);
    botonangulo->setParent(Botones);

}

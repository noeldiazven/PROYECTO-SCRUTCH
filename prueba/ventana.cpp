#include<QMainWindow>
#include "ventana.h"
#include <QLabel>

ventana::ventana()
{
    this->setWindowTitle(QString::fromUtf8("SCRUTCH"));
    this->setWindowIcon(QIcon(":/image/logo.png"));
    this->resize(900,400);
    this->setMinimumSize(QSize(900,400));

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
    operaciones->setStyleSheet("background-color:#A09D9D;");

    //creando el gato
    cat=new Gato();
    cat->setParent(mostrador);
    //creando botones

    //agregandolo al boton mover
    botonmover=new Mover(cat,Botones);

    //agregandolo al boton angulo
    botonangulo=new Angulo(cat,Botones);
    //agregando unica direccion
    botonDireccion=new UnicaDireccion(cat,Botones);
    //agregando el boton correr
    botoninicio=new inicio(cat,Botones);

}

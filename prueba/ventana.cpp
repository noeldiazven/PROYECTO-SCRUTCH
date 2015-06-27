#include<QMainWindow>
#include "ventana.h"
#include <QLabel>

ventana::ventana()
{
    this->setWindowTitle(QString::fromUtf8("SCRUTCH"));
    this->setWindowIcon(QIcon(":/image/logo.png"));
    this->resize(1200,600);
    this->setMinimumSize(QSize(1200,600));
    this->setMaximumSize(QSize(1200,600));

    mostrador=new ventanamostrador(this);

    Botones=new ventanabotones(this,mostrador->get_cat());
    //creando botones

    //agregandolo al boton mover
    botonmover=new Mover(mostrador->get_cat(),Botones);

    //agregandolo al boton angulo
    botonangulo=new Angulo(mostrador->get_cat(),Botones);

    //agregando el boton correr
    botoninicio=new inicio(mostrador->get_cat(),Botones);

    //agregando el boton for
    botonfor=new For(mostrador->get_cat(),Botones);
}

#include <QApplication>
#include "ventana.h"
#include <thread>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ventana * window=new ventana();

    window->show();

    return app.exec();
}
 /***************************************************************************************************
 ***** FALTA EL DESPLAZAMIENTO AL MOMENTO DE AGREGAR Y/O MOVER EL ELEMENTO DE ARRIBA*****************
 ***** FALTA QUE SE AUTOPOSICIONE AL MOMENTO DE ESTAR SERCA DE OTRO ELEMENTO*************************
 ***** FALTA ORDENAR ALGUNAS CLASES Y VER LA MEJOR FORMA DE ABSTRACCION PARA NO HACER COSAS REPETIDAS
 ***************************************************************************************************/

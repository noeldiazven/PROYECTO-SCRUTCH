#include <QApplication>
#include "ventana.h"
#include <thread>
#include <QtGui>
#include "linea.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ventana * window=new ventana();
    window->show();


    return app.exec();
}


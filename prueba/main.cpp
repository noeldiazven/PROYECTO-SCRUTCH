#include <QApplication>
#include <QMainWindow>
#include "ventana.h"
#include <thread>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ventana * window=new ventana();

    window->show();
    return app.exec();
}

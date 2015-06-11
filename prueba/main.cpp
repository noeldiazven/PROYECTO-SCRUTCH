#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
//#include "mylabel.h"
#include "boton.h"
#include "mover.h"
#include "gato.h"
#include <thread>
#include <angulo.h>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //ventana principal
    QMainWindow *window = new QMainWindow();
    //titulo
    window->setWindowTitle(QString::fromUtf8("QT - Capture Mouse Move"));
    window->resize(900, 400);

///////////////////
    QWidget * Botones=new QWidget(window);
    Botones->setGeometry(0,0,300,400);
    Botones->setStyleSheet("background-color:#B5B3B04;");

   // QWidget * Botones1=new QWidget(window);
    //Botones1->setGeometry(0,0,300,400);
   // Botones1->setStyleSheet("background-color:#B5B3B3;");

    QWidget * mostrador=new QWidget(window);
    mostrador->setGeometry(600,0,300,400);
    mostrador->setStyleSheet("background-color:#FFFFFF;");

    QWidget * operaciones=new QWidget(window);
    operaciones->setGeometry(300,0,300,400);
    operaciones->setStyleSheet("background-color:#79E592;");


///////////////////////////////
    Gato * g1=new Gato();
    g1->setParent(mostrador);
///////////////////////////////

    //Boton * boton=new Boton();
    //boton->setParent(Botones);
///////////////////BOTONES/////
    Mover * m1=new Mover(g1);
    m1->setParent(Botones);//agregandolo al widget botones

    Angulo * a1=new Angulo(g1);
    a1->setParent(Botones);//agregandolo al widget botones

///////////////////////////////

    window->show();
    return app.exec();
}

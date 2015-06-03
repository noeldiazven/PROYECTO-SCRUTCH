#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include "mylabel.h"
#include "boton.h"
#include "mover.h"
#include "gato.h"
#include <thread>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow();
    //titulo
    window->setWindowTitle(QString::fromUtf8("QT - Capture Mouse Move"));
    window->resize(700, 400);

    /*QWidget *centralWidget = new QWidget(window);
    QHBoxLayout* layout = new QHBoxLayout(centralWidget);

    myLabel* CoordinateLabel = new myLabel();
    layout->addWidget(CoordinateLabel);

    window->setCentralWidget(centralWidget);*/
///////////////////
    QWidget * Botones=new QWidget(window);
    Botones->resize(350,400);
    Botones->setGeometry(0,0,350,400);
    Botones->setStyleSheet("background-color:#B5B3B3;");

    QWidget * mostrador=new QWidget(window);
    mostrador->resize(350,400);
    mostrador->setGeometry(350,0,350,400);
    mostrador->setStyleSheet("background-color:#FFFFFF;");


///////////////////////////////
    Gato * g1=new Gato();
    g1->setParent(mostrador);
///////////////////////////////

    //Boton * boton=new Boton();
    //boton->setParent(Botones);
///////////////////BOTONES/////
    Mover * m1=new Mover(g1);
    m1->setParent(Botones);

///////////////////////////////

    window->show();
    return app.exec();
}

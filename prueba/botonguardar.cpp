#include "botonguardar.h"
#include "imagenes.h"
#include <QFileDialog>
#include <QDebug>

botonguardar::botonguardar(Gato *g,QLabel * parent)
{
    gato=g;
    this->setGeometry(350,4,30,30);
    this->setPixmap(boton_guardar);
    this->setParent(parent);
}
void botonguardar::mousePressEvent(QMouseEvent *evento)
{
    QString filters("Music files (*.mp3);;Text files (*.txt);;All files (*.*)");
    QString defaultFilter("Text files (*.txt)");

    QString direccion=QFileDialog::getSaveFileName(0, "Save file", QDir::currentPath(),
        filters, &defaultFilter);

    QFile archivo(direccion);
    archivo.open(QIODevice::WriteOnly | QIODevice::Text);
    //poner el texto en el documento
    QTextStream out(&archivo);
    gato->guardarDatos(out);
    archivo.close();
}

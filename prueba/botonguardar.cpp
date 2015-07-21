#include "botonguardar.h"
#include "imagenes.h"
#include <QFileDialog>
#include <QDebug>
#include <windows.h>
#include <QMessageBox>

botonguardar::botonguardar(Gato *g,QLabel * parent)
{
    gato=g;

    posX=350;
    posY=4;
    width=30;
    height=30;

    this->setGeometry(posX,posY,width,height);
    this->setPixmap(boton_guardar);
    this->setParent(parent);
}
void guardadoexitoso(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Guardado!");
    msgBox.setText("Guardado exitoso.");
    msgBox.exec();
}
void botonguardar::guardar(){
    if(file==""){
        QString filters("Music files (*.mp3);;Text files (*.txt);;All files (*.*)");
        QString defaultFilter("Text files (*.txt)");

        QString direccion=QFileDialog::getSaveFileName(0, "Save file", QDir::currentPath(),
            filters, &defaultFilter);
        file=direccion;
    }
    QFile archivo(file);
    archivo.open(QIODevice::WriteOnly | QIODevice::Text);
    //poner el texto en el documento
    QTextStream out(&archivo);
    gato->guardarDatos(out);
    archivo.close();
    if(file!=""){guardadoexitoso();}
}
void botonguardar::mousePressEvent(QMouseEvent *evento)
{
    this->guardar();
}

#include "botonabrir.h"
#include "imagenes.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include "bloques.h"
#include "tipos.h"

botonabrir::botonabrir(Gato *g, QLabel *parent, botonguardar *guardar,ventanabotones * b)
{
    botones=b;
    b_guardar=guardar;
    gato=g;
    this->setGeometry(290,4,30,30);
    this->setPixmap(boton_abrir);
    this->setParent(parent);
}

bool verificarId(QString t,Bloques * a){
    if(a->get_name()==t){
        return true;
    }
    return false;
}

void botonabrir::abrirDatos(QTextStream & a){
    QString text;
    QString text1;
    Bloques * ar;
    std::vector<Bloques*>::iterator it;
    while(true){
        a >> text;
        if(text==""){break;}
        qDebug()<<text;
        for(it=botones->todos_botones.begin();it!=botones->todos_botones.end();it++){
            if(verificarId(text,(*it))){
                ar=(*it);
                ar->abrir(a);
                break;
            }
        }
   }
}

void botonabrir::mousePressEvent(QMouseEvent *evento)
{
    if(b_guardar->noGuardado()){
        if((gato->bloques_activos).size()!=0){
            QMessageBox msgBox;
            msgBox.setWindowTitle("Advertencia");
            msgBox.setText("Se olvido de guardar.Desea guardar? \n Sino perdera todo el archivo.");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            if(msgBox.exec() == QMessageBox::Yes){
                b_guardar->guardar();
            }
        }
        abrir=true;
    }
    if(abrir==true || (!b_guardar->noGuardado())){
        QString filters("Music files (*.mp3);;Text files (*.txt);;All files (*.*)");
        QString defaultFilter("Text files (*.txt)");

        QString direccion=QFileDialog::getOpenFileName(0, "Open file", QDir::currentPath(),
        filters, &defaultFilter);
        if(direccion!=""){gato->borrarTodo();}
        qDebug() << direccion;
        QFile archivo(direccion);
        archivo.open(QIODevice::ReadOnly);
        QTextStream input(&archivo);
        this->abrirDatos(input);
        b_guardar->set_file(direccion);
    }
}

#include "angulo.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>
#include "linea.h"

Linea::Linea(Gato *g,ventanabotones * v){
    obj=g;
    ventana=v;
    this->setParent(ventana);
    this->setGeometry(100,100,200,200);
    this->setPixmap(borrar);
}

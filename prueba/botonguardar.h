#ifndef BOTONGUARDAR_H
#define BOTONGUARDAR_H
#include <QLabel>
#include "gato.h"

class botonguardar:public QLabel
{
private:
    Gato * gato;
    QString file="";
    entero posX,posY,width,height;
public:
    botonguardar(Gato * g,QLabel * parent);
    void mousePressEvent(QMouseEvent * evento);
    void guardar();
    inline void set_file(QString nuevo){file=nuevo;}
    inline QString get_file(){return file;}
    inline bool noGuardado(){return (file=="");}
};

#endif // BOTONGUARDAR_H

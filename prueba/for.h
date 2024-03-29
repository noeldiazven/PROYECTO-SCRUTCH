#ifndef FOR_H
#define FOR_H
#include "bloques.h"
#include "tipos.h"
#include <QWidget>

class For:public Bloques
{
protected:
    entero iteraciones;
public:
    For(Gato * g,ventanabotones * v);
    QLabel * arriba;
    QLabel * abajo;
    QLabel * medio;
    entero lista;
    void correr();
    void crear_nuevo();
    void cambiar_medio(entero x, tipo_entero y);
    inline entero get_size_lista(){return lista;}
    inline void set_size_lista(entero x){lista+=x;}
    virtual QString darValores();
    virtual void abrir(QTextStream & text);
};

#endif // FOR_H

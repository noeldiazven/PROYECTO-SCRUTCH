#ifndef GATO
#define GATO
#include <QLabel>

class Bloques;

typedef QString(IDS);
typedef double(entero);

class Gato:public QLabel{
private:
    entero width;
    entero heigth;

    entero posicion_x;
    entero posicion_y;

    entero cambiar_posicion_x;
    entero cambiar_posicion_y;

    entero receptor;

public:
    Gato();
    entero get_posicion_x();
    entero get_posicion_y();
    entero get_receptor();
    void set_receptor(entero);

    entero get_cambiar_posicion_x();
    entero get_cambiar_posicion_y();

    void set_posicion_y(entero);
    void set_posicion_x(entero);

    void set_cambiar_posicion_x(entero);
    void set_cambiar_posicion_y(entero);

    void mover_gato(entero a,entero b);


    std::vector <Bloques*> bloques_activos;
    void agregar_vector(Bloques * nuevo);
    void verificar(Bloques * nuevo);
};

#endif // GATO


#ifndef GATO
#define GATO
#include<QWidget>

class Gato:public QWidget{
private:
    int x;
    int y;
public:
    Gato();
    void mover(int a);
};

#endif // GATO


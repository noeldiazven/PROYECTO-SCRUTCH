#ifndef ANIMACION_AIMAGEN_H
#define ANIMACION_AIMAGEN_H
#include <QtWidgets/QWidget>

class animacion_aimagen : public QWidget{
    Q_OBJECT
private:
    int x,y;
protected:
    // parapintar el punto verdad en la pantalla
    void paintEvent(QPaintEvent *paint);
public:
    explicit animacion_aimagen(QWidget *parent = 0);
    int getx();
    int gety();
    void setx(int);
    void sety(int);
    void mover(int x,int y);
    void reiniciar(int x,int y);

};

#endif // ANIMACION_AIMAGEN_H

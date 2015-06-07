#ifndef ANIMACION_H
#define ANIMACION_H
#include <QtWidgets/QMainWindow>
#include "gato.h"

namespace Ui {
class animacion;
}

class animacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit animacion(QWidget *parent = 0);
    ~animacion();

protected:

private slots:
    void on_mover_clicked();

    void on_pushButton_clicked();

private:
    Ui::animacion *ui;
    animacion_aimagen *panimacion_aimagen;
};

#endif // ANIMACION_H

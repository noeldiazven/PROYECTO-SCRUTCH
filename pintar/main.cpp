#include "animacion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    animacion w;
    w.show();

    return a.exec();
}

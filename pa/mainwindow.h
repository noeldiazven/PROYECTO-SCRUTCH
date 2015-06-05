#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QLabel>
#include<QString>
#include<QMouseEvent>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QLabel
{
    Q_OBJECT

public:
     MainWindow(){}
};

#endif // MAINWINDOW_H

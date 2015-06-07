#include "animacion.h"
#include "ui_animacion.h"// es la clase gato le cambie de nombr
animacion::animacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::animacion)
{
    ui->setupUi(this);
    //estoy pasando el segundo wiget para que inicie esta pantalla apenas lo corras
    panimacion_aimagen=new animacion_aimagen(this);
    ui->pantalla->addWidget(panimacion_aimagen);
}

animacion::~animacion()
{
    delete ui;
}

void animacion::on_mover_clicked(){
    //QPushButton * boton=new QPushButton("hola mundo");
    //ui->pantalla->addWidget(boton);
    //panimacion es una funcion de ui_animacion.h oesa la calses gato
    int n1=40;
    n1=ui->valor->text().toInt();
    panimacion_aimagen->mover(n1,0);
}

void animacion::on_pushButton_clicked(){
    panimacion_aimagen->reiniciar(40,40);
}

#include "ventanamostrador.h"
#include "imagenes.h"
#include <QDebug>
#include <cmath>
#include <QPainter>

ventanamostrador::ventanamostrador(QWidget *p, ventanabotones *botones)
{
    anteriorX=0;
    activador=40;
    posx=750;
    posy=0;
    width=450;
    heigth=600;
    nuevo=p;
    b=botones;
    comenzar=new QLabel(this);
    comenzar->setGeometry(0,0,450,39);
    comenzar->setPixmap(img_comienzo);

    //creando el gato
    cat=new Gato(this); 
    bandera=new botoncomenzar(cat,comenzar);
    guardar=new botonguardar(cat,comenzar);
    abrir=new botonabrir(cat,comenzar,guardar,b);
    sumador_de_angulo=(cat->get_captor_de_rotacion());
    //mostrar_puntitos();

    posInicialX=cat->get_posicion_x();
    posInicialY=cat->get_posicion_y();


    acumulador=0;
    acumulador1=0;
    comparador=0;

    pi=3.14159265358979323846;
    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#FFFFFF;");
    this->setParent(p);

}

void mostrar_lapiz (QLabel * i) {  // function:
  i->show();
}
void ocultar_lapiz(QLabel * i) {  // function:
  i->hide();
}

void ventanamostrador::pintar_linea(){
    entero div=180;
    anteriorX=cat->get_captor_de_rotacion();

    if(cat->get_activador2()==1){
        if(cat->get_sumador()==1){
           if(cat->get_activador3()==0){
                for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                    pt=new Punto(cat,this,(cat->get_posicion_x()+g)-cat->get_captor_De_mover(),cat->get_posicion_y());
                    //qDebug()<<cat->get_posicion_x()<<"  "<<g;
                     add_lapiz(pt);
                }
                posInicialX=cat->get_posicion_x();
                posInicialY=cat->get_posicion_y();
                cat->set_sumador(0);

           }
           else if(cat->get_activador3()==1){

               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                   add_lapiz(pt);
                   qDebug()<<posInicialX<<" "<<posInicialY<<"esto es de x"<<cos((sumador_de_angulo*pi)/div);

                   posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                   posInicialY-=1*sin((sumador_de_angulo*pi)/div);


               }
                sumador_de_angulo+=cat->get_captor_de_rotacion();

               cat->set_sumador(0);

               cat->set_Activador3(4);

           }
           else if(cat->get_activador3()==2){
               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                   add_lapiz(pt);
                   qDebug()<<posInicialX<<" "<<posInicialY<<"esto es de x"<<cos((sumador_de_angulo*pi)/div);

                   posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                   posInicialY+=1*sin((sumador_de_angulo*pi)/div);


               }
                sumador_de_angulo+=cat->get_captor_de_rotacion();

               cat->set_sumador(0);

               cat->set_Activador3(5);
           }
           else if(cat->get_activador3()==3){
               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                   add_lapiz(pt);
                   qDebug()<<posInicialX<<" "<<posInicialY<<"esto es de x"<<cos((sumador_de_angulo*pi)/div);

                   posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                   posInicialY-=1*sin((sumador_de_angulo*pi)/div);
               }

               if(sumador_de_angulo!=cat->get_captor_de_rotacion()){
                    sumador_de_angulo=cat->get_captor_de_rotacion();
               }
               cat->set_sumador(0);

               cat->set_Activador3(6);
           }
           else if (cat->get_activador3()==4){
               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                   //qDebug()<<cat->get_posicion_x()<<"  "<<g;
                    add_lapiz(pt);
                    posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                    posInicialY-=1*sin((sumador_de_angulo*pi)/div);
               }


               cat->set_sumador(0);
           }
           else if (cat->get_activador3()==5){
               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                   //qDebug()<<cat->get_posicion_x()<<"  "<<g;
                    add_lapiz(pt);
                    posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                    posInicialY+=1*sin((sumador_de_angulo*pi)/div);
               }


               cat->set_sumador(0);
           }
           if(cat->get_activador3()==6){
                for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                    pt=new Punto(cat,this,(cat->get_posicion_x()),cat->get_posicion_y());
                    //qDebug()<<cat->get_posicion_x()<<"  "<<g;

                }

           }
           qDebug()<<posInicialX<<" "<<posInicialY<<"mejor para "<<cos((sumador_de_angulo*pi)/div);
        }
    }
    if(cat->get_activador4()==0){
        if(cat->get_sumador()==1){
           if(cat->get_activador3()==0){
                for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                    pt=new Punto(cat,this,(cat->get_posicion_x()+g)-cat->get_captor_De_mover(),cat->get_posicion_y());
                    //qDebug()<<cat->get_posicion_x()<<"  "<<g;
                    // add_lapiz(pt);
                }
                posInicialX=cat->get_posicion_x();
                posInicialY=cat->get_posicion_y();
                cat->set_sumador(0);

           }
           else if(cat->get_activador3()==1){

               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                  // add_lapiz(pt);
                   qDebug()<<posInicialX<<" "<<posInicialY<<"esto es de x"<<cos((sumador_de_angulo*pi)/div);

                   posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                   posInicialY-=1*sin((sumador_de_angulo*pi)/div);


               }
                sumador_de_angulo+=cat->get_captor_de_rotacion();

               cat->set_sumador(0);

               cat->set_Activador3(4);

           }
           else if(cat->get_activador3()==2){
               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                  // add_lapiz(pt);
                   qDebug()<<posInicialX<<" "<<posInicialY<<"esto es de x"<<cos((sumador_de_angulo*pi)/div);

                   posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                   posInicialY+=1*sin((sumador_de_angulo*pi)/div);


               }
                sumador_de_angulo+=cat->get_captor_de_rotacion();

               cat->set_sumador(0);

               cat->set_Activador3(5);
           }
           else if(cat->get_activador3()==3){
               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                  // add_lapiz(pt);
                   qDebug()<<posInicialX<<" "<<posInicialY<<"esto es de x"<<cos((sumador_de_angulo*pi)/div);

                   posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                   posInicialY-=1*sin((sumador_de_angulo*pi)/div);
               }

               if(sumador_de_angulo!=cat->get_captor_de_rotacion()){
                    sumador_de_angulo=cat->get_captor_de_rotacion();
               }
               cat->set_sumador(0);

               cat->set_Activador3(6);
           }
           else if (cat->get_activador3()==4){
               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                   //qDebug()<<cat->get_posicion_x()<<"  "<<g;
                   // add_lapiz(pt);
                    posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                    posInicialY-=1*sin((sumador_de_angulo*pi)/div);
               }


               cat->set_sumador(0);
           }
           else if (cat->get_activador3()==5){
               for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                   pt=new Punto(cat,this,posInicialX,posInicialY);
                   //qDebug()<<cat->get_posicion_x()<<"  "<<g;
                  //  add_lapiz(pt);
                    posInicialX+=1*cos((sumador_de_angulo*pi)/div);
                    posInicialY+=1*sin((sumador_de_angulo*pi)/div);
               }


               cat->set_sumador(0);
           }
           if(cat->get_activador3()==6){
                for(entero g=0;g<cat->get_captor_De_mover();g+=1){
                    pt=new Punto(cat,this,(cat->get_posicion_x()),cat->get_posicion_y());
                    //qDebug()<<cat->get_posicion_x()<<"  "<<g;

                }

           }
           qDebug()<<posInicialX<<" "<<posInicialY<<"mejor para "<<cos((sumador_de_angulo*pi)/div);
        }
    }

}
void ventanamostrador::eliminar_puntos(){
    while (!lapiz.empty()){
        delete lapiz.back();
        lapiz.pop_back();
    }
}

void ventanamostrador::mostrar_puntitos(){

    std::for_each(lapiz.begin(),lapiz.end(),mostrar_lapiz);
}
void ventanamostrador::paintEvent(QPaintEvent *){

    pintar_linea();
    mostrar_puntitos();
}



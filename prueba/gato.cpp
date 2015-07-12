#include "gato.h"
#include "bloques.h"
#include "imagenes.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QSize>

Gato::Gato(QWidget * par){
    captor_de_rotacion=0;
    captor_de_mover=0;
    controlador_De_lapiz=0;
    parent=par;
    img=image_gato;
    this->setPixmap(img);

    rotar=0;
    posicion_x=200;
    posicion_y=250;
    receptor=0;
    width=80;heigth=80;
    cambiar_posicion_x=0;
    unico_receptor=0;
    activador=0;
    cambiar_posicion_y=0;
    activador_De_punto=0;
    activador3=0;
    activador2=0;
    sumador=0;
    color=0;
    borra=0;


    this->setGeometry(get_posicion_x(),get_posicion_y(),width,heigth);//poniendo en la posicion (x,y) y de tamano (50,50)
    this->setParent(parent);
}


void Gato::rotar_gato(tipo_entero giro){
    rotar+=giro;

    QPixmap rotatedPixmap(img.size());//adapto el valor del img a otro pixmap
    rotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));//cambio el color de fondo
    QPainter* p = new QPainter(&rotatedPixmap);//creo un q painter
    QSize size = img.size();//adapto al tamaño
    p->translate(size.height()/2,size.height()/2);//posiciono al centro
    p->rotate(-rotar);
    p->translate(-size.height()/2,-size.height()/2);
    p->drawPixmap(0, 0, img);
    p->end();
    delete p;
    this->setPixmap(rotatedPixmap);
}

//--------------------------------------VECTOR

void verificar_bucle(Bloques *a,Bloques * b){
    if(a->get_aux()!=nullptr && b->get_aux()==nullptr){
        (a->get_aux())->set_size_lista(1);
        (a->get_aux())->cambiar_medio((a->get_aux())->get_size_lista(),1);
        b->set_aux(a->get_aux());
    }
}

void Gato::agregar_vector(Bloques *nuevo)
{
    bloques_activos.push_back(nuevo);
}

void Gato::sacar_del_vector(Bloques * nuevo){
    if(bloques_activos.size()!=0){
        std::vector<Bloques*>::iterator it;
        it=std::find(bloques_activos.begin(),bloques_activos.end(),nuevo);
        if((*it)==nuevo){bloques_activos.erase(it);}
    }
}

//VERIFICA SI SE ROZAN
inline bool verificar_pos(Bloques * a,Bloques * b){
    if(a!=b){
        if(a->get_id()=="for"){
            if(
              (((a->get_pointer_in_y()+5>=b->get_pointer_up_y())&&(a->get_pointer_in_y()-5<=b->get_pointer_up_y()))&&
               ((a->get_pointer_in_x()+5>=b->get_pointer_up_x())&&(a->get_pointer_in_x()-5<=b->get_pointer_up_x()))
              )
            )
            {
                if(b->get_aux()==nullptr){
                    a->set_size_lista(1);
                    a->cambiar_medio(a->get_size_lista(),1);
                    a->set_dentro(b);
                    b->set_aux(a);
                    return true;
                }
                return false;
            }
        }
        if(
         (((a->get_pointer_back_y()+5>=b->get_pointer_up_y())&&(a->get_pointer_back_y()-5<=b->get_pointer_up_y()))&&
         ((a->get_pointer_back_x()+5>=b->get_pointer_up_x())&&(a->get_pointer_back_x()-5<=b->get_pointer_up_x())))
        ){
            a->set_siguiente(b);
            if(b->get_aux()==nullptr){verificar_bucle(a,b);}
            return true;
        }
        else if(
          ((a->get_pointer_up_y()-5<=b->get_pointer_back_y())&&((a->get_pointer_up_y()+5>=b->get_pointer_back_y()))&&
          ((a->get_pointer_up_x()-5<=b->get_pointer_back_x())&&(a->get_pointer_up_x()+5>=b->get_pointer_back_x())))
        ){
            if(a->get_siguiente()!=b){b->set_siguiente(a);}
            else{a->set_siguiente(nullptr);b->set_siguiente(a);}
            return true;
        }
        else{
            if(a->get_siguiente()==b || a->get_dentro()==b){
                a->set_siguiente(nullptr);
                if(b->get_aux()!=nullptr){
                    (b->get_aux())->set_size_lista(-1);
                    (b->get_aux())->cambiar_medio((b->get_aux())->get_size_lista(),-1);
                     if((b->get_aux())->get_size_lista()==0){
                         (b->get_aux())->set_dentro(nullptr);
                     }
                     b->set_aux(nullptr);
                }
            }
            return false;
        }
        return false;
    }
    return false;
}

//RECORRE LA LISTA
void Gato::verificar(Bloques *nuevo)
{
    std::vector<Bloques*>::iterator it;
    for(it=bloques_activos.begin();it!=bloques_activos.end();it++){
          if(verificar_pos((*it),nuevo)){
              qDebug() << "conectado";
              break;
          }
    }
}

inline void verificar_nombre(Bloques * nuevo){
    if(nuevo->get_id()=="inicio"){
        nuevo->correr();
    }
}
void Gato::correr_vector()
{
    std::vector<Bloques*>::iterator it;
    for(it=bloques_activos.begin();it!=bloques_activos.end();it++){
        verificar_nombre((*it));
    }
}


//---------------------------------------
void Gato::mover_gato(entero a, entero b){
    if(get_activador()==0){
        set_posicion_x(a);
        set_posicion_y(b);
        this->setGeometry(get_posicion_x(),get_posicion_y(),width,heigth);}

    else if(get_activador()==1){
        set_posicion_x(-a);
        set_posicion_y(b);
        this->setGeometry(get_posicion_x(),get_posicion_y(),width,heigth);}

    else if(get_activador()==2){
        set_posicion_x(a);
        set_posicion_y(-b);
        this->setGeometry(get_posicion_x(),get_posicion_y(),width,heigth);}

    else if(get_activador()==3){
        set_posicion_x(a);
        set_posicion_y(b);
        this->setGeometry(get_posicion_x(),get_posicion_y(),width,heigth);}
}

void Gato::rotar_gato_unica_direccion(tipo_entero valor){
    QPixmap rotatedPixmap(img.size());//adapto el valor del img a otro pixmap
    rotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));//cambio el color de fondo
    QPainter* p = new QPainter(&rotatedPixmap);//creo un q painter
    QSize size = img.size();//adapto al tamaño
    p->translate(size.height()/2,size.height()/2);//posiciono al centro
    p->rotate(-valor);
    p->translate(-size.height()/2,-size.height()/2);
    p->drawPixmap(0, 0, img);
    p->end();
    delete p;
    this->setPixmap(rotatedPixmap);
}

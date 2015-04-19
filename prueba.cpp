#include<iostream>
using namespace std;

typedef int T;

template<typename valor>

class prueba{
    valor x;
    valor y;
public:
    prueba(valor eje_x=0,valor eje_Y=0){
        x=eje_x;
        y=eje_Y;
    }
    valor sumar_valores(valor,valor);
    void multiplicar_valores(T*);
    void Display(){ cout<< x<< "," <<y<<endl; }
};
// siempre se pone template de nuevo aqui abajo
template<typename valor>
valor prueba<valor>::sumar_valores(valor a,valor b){
    return a+b;
}
template<typename valor>
void prueba<valor>::multiplicar_valores(T * resultado){
    *resultado=x*y;
}
///////////////////////////////////////////////////
///////////SMART POINTER//////////////////////////
//////////////////////////////////////////////////


//////cree una clase para hacer una prueba//////
class recta{
    int x,y;
public:
    recta(){x=0; y=0;}
    recta(int n_x, int n_y){x=n_x; y=n_y;}
    void display_r(){cout<<x<<","<<y<<endl;}
};

///////clase smart pointer con template//////
template<typename P> class s_pointer
{
    P *m_p;
public:


    s_pointer(P * new_m_p) : m_p(new_m_p)
    {
    }
    ~s_pointer()
    {
        delete m_p;
    }
    //////genero sobre carga de operador para que pueda hacer el llamado a display mediante el smart pointer//////
    recta* operator -> (){
        return m_p;
    }



};



int main(){
   prueba <int>uno(5,6);

    uno.Display();
    cout<<uno.sumar_valores(4,4)<<endl;
    T resultado;
    uno.multiplicar_valores(&resultado);
    cout<<resultado<<endl;
    //////////////////////////////////////////
    //////Prueba de punteros inteligentes////
    ////////////////////////////////////////

    s_pointer <recta> r1(new recta(3,1));
    r1->display_r();




    return 0;
}
// ayque implementar los smart points

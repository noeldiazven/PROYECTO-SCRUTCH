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
int main(){
    prueba <int>uno(5,6);
    cout<<uno.sumar_valores(4,4)<<endl;
    T resultado;
    uno.multiplicar_valores(&resultado);
    cout<<resultado;
    return 0;
}

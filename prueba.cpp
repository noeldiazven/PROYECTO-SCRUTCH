#include<iostream>
using namespace std;

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
};
// siempre se pone templete denuevo aqui avajo
template<typename valor>
valor prueba<valor>::sumar_valores(valor a,valor b){
    return a+b;
}
int main(){
    prueba <int>uno;
    cout<<uno.sumar_valores(4,4);
    return 0;
}

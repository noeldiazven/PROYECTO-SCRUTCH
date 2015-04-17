#include<iostream>
using namespace std;
typedef int T;

/*MODIFIQUEN ESTE CODIGO PARA PROBAR*/
/*PRUEBEN TODOS LOS COMANDOS DE GITHUB*/

class prueba{
private:
    T valor;
public:
    prueba(T valor_inicial=0){valor=valor_inicial;}
    void cambiar(T nuevo){valor=nuevo;}
    void print(){cout<<this->valor<<endl;}
};

int main(){
    cout<<"hello world"<<endl;
    prueba nuevo;
    nuevo.print();
    nuevo.cambiar(4);
    nuevo.print();
    return 0;
    }

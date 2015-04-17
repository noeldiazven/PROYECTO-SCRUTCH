#include<iostream>
using namespace std;
typedef int T;

/*MODIFIQUEN ESTE CODIGO PARA PROBAR*/

class prueba{
private:
    T valor;
public:
    prueba(){valor=0;}
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

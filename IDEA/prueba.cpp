
#include<iostream>

using namespace std;
class Block{
public:

    virtual void correr(){}

};

class Mover:public Block{

private:

    int num_pasos;
    Block* siguiente;

public:
    Mover(int a){num_pasos=a;siguiente=NULL;}

    void correr(){
        cout<<"mover"<<num_pasos<<"pasos"<<endl;
        if(siguiente!=NULL){siguiente->correr();}
    }

    void set_siguiente(Block* nuevo){siguiente=nuevo;}
    Block * get_siguiente(){return siguiente;}
};

class For{

private:

    int number_iterator;
    Block * contenido;

public:
    For(){number_iterator=10;contenido=NULL;}

    void set_number_iterator(int a){number_iterator=a;}

    Block* get_contenido(){return contenido;}

    void set_contenido(Block* nuevo){contenido=nuevo;}

    void correr(){
        for(;number_iterator>0;number_iterator--){
            contenido->correr();
        }
    }
};
int main(){

    For * nuevo=new For();
    Mover * n1=new Mover(10);
    Mover * n2=new Mover(3);
    n1->set_siguiente(n2);
    nuevo->set_number_iterator(11);
    nuevo->set_contenido(n1);
    nuevo->correr();
    return 0;

    }

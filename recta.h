#ifndef RECTA_H
#define RECTA_H
#include<iostream>

using namespace std;

class recta{
    int x,y;
public:
    recta(){x=0; y=0;}
    recta(int n_x, int n_y){x=n_x; y=n_y;}
    void display_r(){cout<<x<<","<<y<<endl;}
};

#endif // RECTA_H

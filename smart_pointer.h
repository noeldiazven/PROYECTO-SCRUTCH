#ifndef SMART_POINTER_H
#define SMART_POINTER_H
#include "recta.h"
template<typename P>
class smart_pointer
{
    P *m_p;
    public:
        smart_pointer(P * new_m_p) : m_p(new_m_p){}
        ~smart_pointer(){
            delete m_p;
        }
        //////genero sobre carga de operador para que pueda hacer el llamado a display mediante el smart pointer//////
        recta* operator -> (){
            return m_p;
        }
};

#endif // SMART_POINTER_H

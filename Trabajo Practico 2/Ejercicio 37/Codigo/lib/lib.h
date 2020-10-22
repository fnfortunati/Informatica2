#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

//Tipo de dato

struct d{                                                
    long clave; //Clave o Id del registro
    char c[30];//Descripcion                                         
    unsigned char tipo; //Tipo de datos como entero sin signo                                               
    char b; //'A':Alta  'B':Baja                                                                                             
};

struct pila{
    struct d dato;
    struct pila *l;
};

//Prototipos de funciones

#endif
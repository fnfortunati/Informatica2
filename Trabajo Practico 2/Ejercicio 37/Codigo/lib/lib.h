#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

//Tipo de dato

typedef struct {                                                
    long clave; //Clave o Id del registro
    char c[30];//Descripcion                                         
    unsigned char tipo; //Tipo de datos como entero sin signo                                               
    char b; //'A':Alta  'B':Baja                                                                                             
}datos_t;

typedef struct {
    long clave;
    char descrip[30];
    uint8_t pos;
}clyp;

struct pila{
    clyp d;
    struct pila *l;
};

//Prototipos de funciones

void genero (void);
void cargar_arch (void);
struct pila * buscar_reg (void);
struct pila * cargar (struct pila *,clyp);

void mostrar_arch (void);
void mostrar_pila (struct pila *p);

#endif
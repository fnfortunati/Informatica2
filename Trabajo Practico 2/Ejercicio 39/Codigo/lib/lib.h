#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

typedef struct {
    char desc[60];
    unsigned char potencia;
    unsigned int estado;
}medicion;

struct lista{
    medicion dato;
    struct lista *l;
};


//Prototipos

struct lista * cargar (struct lista *);
void mostrar_lista (struct lista  *);

#endif
#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

typedef struct{
    long partNumber;
    long serialNumber;
    char descripcion[40];       
    char ubicacion[100]; 
    char estatus;      
}repuestos_t;

struct lista {
    repuestos_t info;
    struct lista *l;
};


//Prototipos

void cargar (struct lista **);
struct lista * listar (struct lista *,struct lista **, repuestos_t);
void muestro_lista (struct lista *);
void cargo_arch (struct lista **);

#endif
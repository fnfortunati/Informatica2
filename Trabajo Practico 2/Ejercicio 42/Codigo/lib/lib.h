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

struct cola {
    repuestos_t info;
    struct cola *ant,*sig;
};


//Prototipos

void buscar (void);
uint8_t rev_bit (repuestos_t bf);
struct cola * cargar (struct cola *, struct cola **,repuestos_t);
void crear_arch (struct cola **);
void baja (void);
void mostrar_arch (void);

#endif
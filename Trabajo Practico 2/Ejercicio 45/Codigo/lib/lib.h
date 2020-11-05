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
}repuestos_t;

typedef struct{
    repuestos_t repuesto;        
    int cantidad;
}extraccionRepuestos_t;

struct pila{
    repuestos_t pieza;
    char sacar;
    struct pila *l;
};

struct cola {
    extraccionRepuestos_t pieza;
    struct cola *l;
};


//Prototipos

int cuenta_datos (void);
repuestos_t * bajar_arch (void);
struct pila * cargar (repuestos_t *);
struct cola * buscar (extraccionRepuestos_t,struct pila *, struct cola *);
struct cola * arm_cola (struct cola *,long , uint8_t);
void act_arch (struct pila *);

#endif
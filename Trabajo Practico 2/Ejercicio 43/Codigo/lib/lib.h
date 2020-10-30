#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

typedef struct{
    long numeroDeOrden;
    char cliente[40];       
    char descripciondeFalla[200];        
    char modelo[65];
    char fecha[10];
    char hora[10];
    char estado;
}fallas_t;

struct pila {
    fallas_t info;
    struct pila *l;
};

struct lista{
    fallas_t info;
    struct lista *l;
};


//Prototipos

uint8_t menu (void);
void crear_arch (void);
void carga (void);
void reparado (void);
struct pila * apilar (void);
struct lista * ordenar (struct lista *);
void mostrar_pila (struct pila *);

#endif
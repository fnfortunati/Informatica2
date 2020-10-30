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
}repuestos_t;

struct cola {
    repuestos_t info;
    struct cola *ant,*sig;
};


//Prototipos

uint8_t menu (void);
void crear_arch (void);
void carga (void);
void reparado (void);
#endif
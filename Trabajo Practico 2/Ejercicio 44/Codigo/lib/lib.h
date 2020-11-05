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

struct lista{
    extraccionRepuestos_t dato;
    struct lista *ant;
    struct lista *sig;
};

//Prototipos

uint8_t menu (void);
void cargar (extraccionRepuestos_t);
uint8_t buscar (extraccionRepuestos_t, struct lista *);
struct lista * listar (struct lista *, struct lista **, extraccionRepuestos_t);

#endif
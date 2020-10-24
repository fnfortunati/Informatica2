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
}medicion_t;

typedef struct {
    uint8_t id;
    medicion_t dato;
    char b;
}pot_t;

struct lista{
    medicion_t dato;
    struct lista *l;
};


//Prototipos

struct lista * cargar (struct lista *);
void archivo (struct lista  *);
void mostrar_arch (void);

#endif
#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

//Tipo de dato

typedef struct {
    char nombre [10];
    char apellido [10];
    uint8_t edad;
    char telefono [15];
    char mail [30];
}persona_t;

struct pila{
    persona_t dato;
    struct pila *l;
};

//Prototipos de la funcion

struct pila * cargar (struct pila *,struct pila *);

void archivo (persona_t);

#endif 
#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

//Tipo de dato

typedef struct {
    char nombre [1];
    char apellido [10];
    uint8_t edad;
    char telefono [15];
    char mail [30];
}persona_t;

struct lista{
    persona_t dato;
    struct lista *l;
};

//Prototipos de funciones

int cuenta_datos (void);
persona_t * bajar_arch (void);
struct lista * cargar (persona_t *);
void archivo (persona_t);
void mostrar_arch (void);

#endif
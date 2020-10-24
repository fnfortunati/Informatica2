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

struct pila{
    unsigned char potencia;
    struct pila *l;
};

//Prototipos

void buscar_reg (void);
char * primera (char *p);
void actualizar_arch (pot_t,uint8_t);
void rev_bit (void);
struct pila * cargar_pila (struct pila *p,unsigned char);
void arch_sec (medicion_t);

#endif
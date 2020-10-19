#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

typedef struct {
    char nombre [20];
    char apellido [20];
    uint8_t edad;
    char telefono [20];
    char mail [30];
}persona_t;

#endif
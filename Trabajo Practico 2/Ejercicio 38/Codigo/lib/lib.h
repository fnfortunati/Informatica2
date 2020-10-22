#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef unsigned char uint8_t;

struct cola {
    uint8_t muestra;
    struct cola *l;
};

//Prototipos

struct cola * muestras (void);

#endif
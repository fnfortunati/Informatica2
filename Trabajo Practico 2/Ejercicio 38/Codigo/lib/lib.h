#ifndef MY_LIB  
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

typedef unsigned char uint8_t;

struct cola {
    uint8_t muestra;
    struct cola *ant,*sig;
};

//Prototipos

struct cola * muestras (struct cola *,struct cola **);
void signal (struct cola *, struct cola **);

#endif
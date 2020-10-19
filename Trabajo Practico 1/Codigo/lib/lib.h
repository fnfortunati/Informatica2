#ifndef MY_LIB
#define MY_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
 
typedef unsigned char uint8_t;

 // Estados posibles

typedef enum {
    espera,     //espera = 0
    barr_ent,   //barr_ent = 1
    barr_sal,   //barr_sal = 2
    aviso,      //aviso = 3
}estados_t;

//Estructura de datos de configuración

typedef struct {
    unsigned char cant;     //cantidad actual
    unsigned char cant_set; //cantidad seteada
    unsigned char deltaC;   //delta de cantidad 
}cantidad_t;

//Prototipos de funciones a usar

estados_t (*f_estado[4])(cantidad_t*,uint8_t*);

void f_inicio (cantidad_t *);
estados_t f_espera (cantidad_t *,uint8_t *);
estados_t f_ent (cantidad_t *, uint8_t *);
estados_t f_sal (cantidad_t *, uint8_t*);
estados_t f_aviso (cantidad_t *, uint8_t*);

char * getKey (char *key);
void parConfig (char *,cantidad_t*);

uint8_t b_ent (void);
uint8_t b_sal (void);

#endif

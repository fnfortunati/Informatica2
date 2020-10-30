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
}fallas_t;

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


//Prototipos



#endif
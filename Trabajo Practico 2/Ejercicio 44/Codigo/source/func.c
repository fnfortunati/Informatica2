#include "../lib/lib.h"

uint8_t menu (void){
    uint8_t opc;

    system ("cls");

    printf ("\nMenu: ");
    printf ("\n\n1. Cargar Orden");
    printf ("\n2. Cargar reparado");
    printf ("\n3. Salir");
    scanf ("%d", &opc);

    return opc;
}
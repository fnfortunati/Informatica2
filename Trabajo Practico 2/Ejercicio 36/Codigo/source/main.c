#include "../lib/lib.h"

int main (void){
    struct lista *p=NULL,*u=NULL,*aux,*r;

    uint8_t cant = 0;

    cant = cuenta_datos ();

    printf ("\nLa cantidad de datos es: %d", cant);

    return 1;
}
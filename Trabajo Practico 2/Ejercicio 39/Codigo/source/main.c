#include "../lib/lib.h"

int main (void){
    struct lista *p=NULL;

    p = cargar (p);
    
    printf ("\nCargue la lista.");
    getchar ();
    
    mostrar_lista (p);
}
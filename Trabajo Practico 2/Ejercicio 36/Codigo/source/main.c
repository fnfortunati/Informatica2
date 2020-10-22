#include "../lib/lib.h"

int main (void){
    struct lista *p; //=NULL,*u=NULL,*aux,*r;

    uint8_t cant = 0, i=0;

    persona_t *d;

    //Bajo el archivo a memoria

    d = bajar_arch();

    //Armado de lista
    
    p = cargar (d);
 
    //Armo el archivo lista
    
    while (p){  
        archivo (p->dato);
        p=p->l;
    }
    
    //Muestro la lista
    
    mostrar_arch ();

    free(p);

    return 0;
}
#include "../lib/lib.h"

int main (void){
    struct lista *p; //=NULL,*u=NULL,*aux,*r;

    uint8_t cant = 0, i=0;
    persona_t *d;

    FILE *fp;

    if((fp=fopen("../../../Ejercicio 35/Codigo/contactos.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }
    
    cant = cuenta_datos ();

    //Bajo el archivo a memoria
    d=(persona_t *) malloc (sizeof (persona_t) * cant);
    fread (d,sizeof (persona_t),cant,fp);

    fclose(fp);

    //Armado de lista
    
    p = cargar (d,cant);
 
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
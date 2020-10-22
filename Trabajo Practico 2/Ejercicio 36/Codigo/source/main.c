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

    //Armado de lista
    
    p = cargar (d,cant);
 
    //Muestro la lista
    
    while (p){
        printf ("\n%-10s\t%-10s\t%2d\t%-15s\t%-30s",p->dato.apellido,p->dato.nombre,p->dato.edad,p->dato.telefono,p->dato.mail);
        p=p->l;
    }
    free(p);

    getchar();

    //FALTA PROBAR Y ARMAR EL ARCHIVO

    return 1;
}
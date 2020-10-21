#include "../lib/lib.h"

int main (void){
    struct lista *p=NULL,*u=NULL,*aux,*r;

    uint8_t cant = 0, i;
    persona_t *d;

    FILE *fp;

    if((fp=fopen("../../../Ejercicio 35/Codigo/contactos.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }
    
    cant = cuenta_datos ();
    
    //Bajo el archivo a memoria
    d=(persona_t *) malloc (sizeof (persona_t) * cant);
    fread (d,sizeof (persona_t),cant,fp);

    //Armo la lista

    aux = (struct lista *)malloc (sizeof(struct lista));

    if (aux){
        for (i=0; i<cant; i++){
            //Primer elemento
            aux->dato = d [i];
            if (p==NULL){
                p=u=aux;
                u->l=NULL;
            }
            else
            {
                r=p;
                while (1){
                    //Primer lugar de la lista
                    if (strcmp (r->dato.apellido,aux->dato.apellido)>=0){
                        aux->l=p;
                        p=aux;
                        break;
                    }
                    while (r->l)
                        if (strcmp (r->l->dato.apellido,aux->dato.apellido)<0)
                            r=r->l;
                        else
                            break;
                    //Ultimo lugar
                    if (r==u){
                        u->l=aux;
                        u=aux;
                        u->l=NULL;
                        break;
                    }
                    //Lugar central
                    aux->l=r->l;
                    r->l=aux;
                }
            }
            
        }
    }


    //Muestro la lista

    aux=p;

    while (aux){
        printf ("\n%-10s\t%-10s\t%2d\t%-15s\t%-30s",aux->dato.apellido,aux->dato.nombre,aux->dato.edad,aux->dato.telefono,aux->dato.mail);
        aux=aux->l;
    }
    free(aux);

    //FALTA PROBAR Y ARMAR EL ARCHIVO

    return 1;
}
#include "../lib/lib.h"

//Funcion para armar la pila

struct pila * cargar (struct pila *p, struct pila *aux){
    system ("cls");
    aux = (struct pila *) malloc (sizeof (struct pila));
    if (aux){
        fflush (stdin);
        printf ("\nIngrese el Nombre: ");
        gets (aux->dato.nombre);
        printf ("\nIngrese el Apellido: ");
        gets (aux->dato.apellido);
        fflush(stdin);
        printf ("\nIngrese la Edad: ");
        scanf ("%d",&aux->dato.edad);
        fflush(stdin);
        printf ("\nIngrese el Telefono: ");
        gets (aux->dato.telefono);
        printf ("\nIngrese el Mail: ");
        gets (aux->dato.mail);

        if (aux->dato.edad >21){
            archivo (aux->dato);
        }
        aux->l=p;
        p=aux;    
    }

    return p;
}

void archivo (persona_t bf){
    FILE *fp;

    if ((fp=fopen ("../contactos.dat","ab"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        return;
    }

    fwrite (&bf, sizeof (persona_t),1,fp);
    fclose (fp);
}

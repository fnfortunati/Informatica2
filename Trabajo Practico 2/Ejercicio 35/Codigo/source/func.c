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

void mostrar_arch (void){
    FILE *fp;
    persona_t bf;
    
    if ((fp=fopen ("../contactos.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }

    fread (&bf, sizeof (persona_t),1,fp);
    printf("\n\nImpresion de archivo\n\n");
    while (!feof(fp)){
        printf ("\n%-10s\t%-10s\t%2d\t%-15s\t%-30s",bf.nombre,bf.apellido,bf.edad,bf.telefono,bf.mail);
        fread (&bf, sizeof (persona_t),1,fp);
    }
    fclose (fp);
}

void mostrar_pila (struct pila *p,struct pila *aux){
    system ("cls");
    printf("\n");
    printf ("NOMBRE----------APELLIDO-------EDAD-----TELEFONO-----------MAIL-----------");
        
    do{
        aux=p;
        printf ("\n%-10s\t%-10s\t%2d\t%-15s\t%-30s",p->dato.nombre,p->dato.apellido,p->dato.edad,p->dato.telefono,p->dato.mail);
        p=p->l;
        free(aux);
    }while(p!=NULL);
}

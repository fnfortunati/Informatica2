#include "../lib/lib.h"

int main (void){
    struct pila *p=NULL, *aux;
    uint8_t opc=1;

    do{
        p = cargar (p,aux);

        printf ("\n\nQuiero agregar a otra persona ? 0-No   1-Si: ");
        scanf ("%d", &opc);
    }while(opc!=0);

        
    system ("cls");
    printf("\n");
    printf ("NOMBRE----------APELLIDO-------EDAD-----TELEFONO-----------MAIL-----------");
        
    do{
        aux=p;
        printf ("\n%-10s\t%-10s\t%2d\t%-15s\t%-30s",p->dato.nombre,p->dato.apellido,p->dato.edad,p->dato.telefono,p->dato.mail);
        p=p->l;
        free(aux);
    }while(p!=NULL);

    return 0;
}
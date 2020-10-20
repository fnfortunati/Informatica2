#include "../lib/lib.h"

int main (void){
    struct pila *p=NULL,*aux;
    uint8_t opc=1;

    persona_t bf;
    FILE *fp;

    do{
        p = cargar (p,aux);

        printf ("\n\nQuiere agregar a otra persona ? 0-No   1-Si: ");
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

    printf ("\n\nPrueba de archivo:\n\n");
    
    if ((fp=fopen ("../contactos.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        return 1;
    }

    fread (&bf, sizeof (persona_t),1,fp);
    while (!feof(fp)){
        printf ("\n%-10s\t%-10s\t%2d\t%-15s\t%-30s",bf.nombre,bf.apellido,bf.edad,bf.telefono,bf.mail);
        fread (&bf, sizeof (persona_t),1,fp);
    }
    fclose (fp);

    return 0;
}
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
 
    mostrar_pila (p,aux);
    mostrar_arch();

    return 0;
}
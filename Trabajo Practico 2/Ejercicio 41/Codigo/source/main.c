#include "../lib/lib.h"

int main (void){
    uint8_t opc;
    struct lista *p=NULL;
    
    do{
        p = cargar (p);
        
        fflush (stdin);
        printf ("\n\nDesea cargar otra pieza ? 0-No 1-Si ");
        scanf ("%d",&opc);
    }while (opc != 0);
    return 0; 
}
#include "../lib/lib.h"

int main (void){
    uint8_t id,opc,i;
    pot_t bf;

    FILE *fp;

    do{
        buscar_reg ();
        printf ("\nQuiere buscar otro id ? 0-No 1-Si ");
        scanf ("%d",&opc);
    }while (opc !=0);

    rev_bit();

    return 0;    
}
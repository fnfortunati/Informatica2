#include "../lib/lib.h"

struct frase{    
    char bf[40];
};

int main (void){
    uint8_t i;
    struct frase bf;
    FILE *fp;
    
    char *p;

    fp = fopen ("prueba.dat","wb");

    for (i=0;i<2;i++){
        fflush (stdin);
        printf ("\nIngrese dos palabras: ");
        gets (bf.bf);

        printf ("\n\n%s",bf.bf);
    }
}
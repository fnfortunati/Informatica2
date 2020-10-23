#include "../lib/lib.h"

int main (void){
    struct cola *p=NULL,*u=NULL;

    uint8_t opc;
    
    //Armo las muestras

    p=muestras(p,&u);
    
    //Imprimo la señal

    do{
        signal(p,&u);
        if (kbhit())
            opc = getch();
    }while (opc !=27);
    
}
#include "../lib/lib.h"

struct cola * muestras (void){
    struct cola *p=NULL,*u=NULL,*aux;
    uint8_t i;

    for (i=0;i<128;i++){
        aux = (struct cola *)malloc (sizeof (struct cola));
        if (aux){
            aux->muestra = i;

            if (p==NULL)
                p=u=aux;
            else{
                u->l=aux;
                u=aux;
            }

            u->l=NULL;
        }
    }

    return p;
}
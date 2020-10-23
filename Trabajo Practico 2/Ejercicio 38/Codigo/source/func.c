#include "../lib/lib.h"


//Armo las muestras

struct cola * muestras (struct cola *p, struct cola **u){
    struct cola *aux;
    uint8_t i;
    double pi = 3.14159;

    for (i=0;i<=18;i++){
        aux = (struct cola *)malloc (sizeof (struct cola));
        if (aux){
            aux->muestra = (sin(((i*5)*pi)/180)*127);

            if (p==NULL){
                p=*u=aux;
                p->ant=NULL;
                p->sig=NULL;
            }
            else{
                (*u)->sig=aux;
                aux->ant = *u;
                aux->sig=NULL;
                *u=aux;
            }
        }
    }

    return p;
}

void signal (struct cola *p, struct cola **u){
    struct cola *aux;
    uint8_t i=0,desp=0;

    do{
        if (i!=0)
            desp = 7;
            
        aux=p;
        do{
            printf ("\n%d",(aux->muestra)|(1<<desp));
            aux=aux->sig;
        }while (aux!=NULL);

        aux=(*u)->ant;
        do{
            printf ("\n%d",(aux->muestra)|(1<<desp));
            aux=aux->ant;
        }while (aux!=NULL);
        i++;
    }while (i!=2);
}

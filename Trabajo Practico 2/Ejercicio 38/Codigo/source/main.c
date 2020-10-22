#include "../lib/lib.h"

int main (void){
    struct cola *p=NULL,*aux;
    uint8_t i=1,opc;

    p = muestras();
   
    do{
        switch (i){
            case 1:
                aux=p;
                do{
                    printf ("\n%d",aux->muestra);
                    aux=aux->l;
                }while (aux!=NULL);
                break;
            case 2:
                aux=p;
                do{
                    printf ("\n%d", 127-aux->muestra);
                    aux=aux->l;
                }while (aux!=NULL);
                break;
            case 3:
                aux=p;
                do{
                    aux->muestra=aux->muestra|(1<<7);
                    printf ("\n%d",aux->muestra);
                    aux=aux->l;
                }
                while (aux!=NULL);
                break;
            case 4:
                aux=p;
                do{
                    aux->muestra=aux->muestra|(1<<7);
                    printf ("\n%d",255-(aux->muestra));
                    aux=aux->l;
                }while (aux!=NULL);
                break;
        }
        i++;
        if(i>4)
            i=1;

        if (kbhit())
            opc = getch();
    }while (opc !=27);


/*
    do{
        printf ("\n%d",p->muestra);
        aux=p;
        p=p->l;
        free (aux);
    }while (p!=NULL);

    getchar();
*/
}
#include "../lib/lib.h"


struct lista * cargar (struct lista *p){
    struct lista *aux,*u,*r;
    uint8_t opc=0;
    
    do{
        system ("cls");
        aux = (struct lista *) malloc (sizeof (struct lista));
        if (aux){
            fflush (stdin);
            printf ("\nIngrese la Descripcion: ");
            scanf ("%s", &aux->dato.desc);
            fflush (stdin);
            printf ("\nIngrese la Potencia: ");
            scanf ("%d",&aux->dato.potencia);
            aux->dato.estado = aux->dato.desc[0] * aux->dato.potencia;

            if (p==NULL){
                    p=u=aux;
                    u->l=NULL;
            }
            else{
                r=p;
                while (1){
                    if (r->dato.potencia < aux->dato.potencia){
                        aux->l=p;
                        p=aux;
                        break;
                    }
                    while (r->l) {
                        if(r->l->dato.potencia > aux->dato.potencia)
                            r=r->l;
                        else
                            break;
                    }
                    if (r==u){
                        u->l=aux;
                        u=aux;
                        u->l=NULL;
                        break;
                    }
                    
                    aux->l=r->l;
                    r->l=aux;
                    break;
                }
            }
        }
        
        printf ("\n\nQuiere agregar a otra persona ? 0-No   1-Si: ");
        scanf ("%d", &opc);

    }while (opc != 0);

    return p;
}

void mostrar_lista (struct lista *p){
    struct lista *aux;

    aux = p;

    while (aux){
        printf ("\n%-20s\t%-d\t%d",aux->dato.desc,aux->dato.potencia,aux->dato.estado);
        aux = aux->l;
    }

    getchar ();
}
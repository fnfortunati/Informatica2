#include "../lib/lib.h"

uint8_t menu (void){
    uint8_t opc;

    system ("cls");

    printf ("\nMenu: ");
    printf ("\n\n1. Cargar Repuestos");
    printf ("\n2. Salir");
    scanf ("%d", &opc);

    return opc;
}

void cargar (extraccionRepuestos_t pieza){
    struct lista *p = NULL, *r = NULL;
    uint8_t flag;

    flag = buscar (pieza,p);

    if (flag == 0)
        p = listar (p,&r,pieza);
}

uint8_t buscar (extraccionRepuestos_t pieza, struct lista *p){
    struct lista *aux;
    uint8_t flag = 0;

    aux = p;

    while (aux){
        if (pieza.repuesto.partNumber == aux->dato.repuesto.partNumber){
            aux->dato.cantidad += pieza.cantidad;
            flag = 1;
        }
        aux = aux->sig;
    }

    return flag;
}

struct lista * listar (struct lista *p, struct lista **r, extraccionRepuestos_t pieza){
    struct lista *aux = NULL;

    aux = (struct lista *) malloc (sizeof (struct lista ));
    
    if (aux){
        aux->dato = pieza;

        if (p==NULL){
            p=aux;
            p->ant = NULL;
            p->sig  = NULL;
        }
        else{
            *r = p;
            while (((*r)->dato.repuesto.partNumber <= aux->dato.repuesto.partNumber)&&(p->sig != NULL)){
                p = p->sig;
            }
            if ((*r)->dato.repuesto.partNumber > aux->dato.repuesto.partNumber){
                if (aux->ant != NULL)
                    aux->ant->sig = aux;
                else
                    p = aux;
                aux->ant = (*r)->ant;
                (*r)->ant = aux;
                aux->sig = *r;
            }
            else{
                (*r)->sig = aux;
                aux->ant = *r;
                aux->sig = NULL;
            }
        }
    }

    return p;
}
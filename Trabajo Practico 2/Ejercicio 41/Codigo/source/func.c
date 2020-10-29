#include "../lib/lib.h"

void cargar (struct lista **p){
    repuestos_t aux;
    uint8_t opc;

    struct lista *s,*u = NULL;

    s = *p;

    system ("cls");
    fflush (stdin);
    
    printf ("\nIngrese el Numero de parte: ");
    scanf ("%ld",&aux.partNumber);
    printf ("\nIngrese el Numero de serie: ");
    scanf ("%ld",&aux.serialNumber);
    fflush (stdin);
    printf ("\nIngrese la Descripcion: ");
    gets (aux.descripcion);
    printf ("\nIngrese la Ubicacion: ");
    gets (aux.ubicacion);
    aux.estatus = 'A';

    s = listar (s,&u,aux);

    muestro_lista (s);

    *p = s;
}

struct lista * listar (struct lista *p,struct lista **u, repuestos_t dato){
    struct lista *aux,*r;

    aux = (struct lista *) malloc (sizeof (struct lista));

    if (aux){
        aux->info = dato;

        if (p == NULL){
            p=*u=aux;
            (*u)->l=NULL;
        }
        else{
            r=p;
            while (1){
                if ((strcmp (r->info.descripcion,aux->info.descripcion))>0){
                    aux->l = p;
                    p=aux;
                    break;
                }
                while (r->l){
                    if((strcmp(r->l->info.descripcion,aux->info.descripcion))<0)
                        r=r->l;
                    else
                        break;
                }
                if (r==*u){
                        (*u)->l=aux;
                        *u=aux;
                        (*u)->l=NULL;
                        break;
                }
                aux->l=r->l;
                r->l=aux;
                break;
            }
        }
    }

    return p;
}

void muestro_lista (struct lista *p){
    struct lista *aux;

    while (p){
        aux = p; 
        printf ("\n%-4d\t%-4d\t%-15s\t%-15s", p->info.partNumber,p->info.serialNumber,p->info.descripcion,p->info.ubicacion);
        p=p->l;
    }
}

void cargo_arch (struct lista **p){
    struct lista *aux;
    repuestos_t bf;

    FILE *fp;

    if ((fp=fopen ("../stock.dat","ab"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        getchar ();
    }

    while (*p){
        aux = *p;
        bf = aux->info;

        fwrite (&bf,sizeof(repuestos_t),1,fp);
        *p = (*p)->l;
        free (aux);
    }
    fclose (fp);
}
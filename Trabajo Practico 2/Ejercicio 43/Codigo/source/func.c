#include "../lib/lib.h"

uint8_t menu (void){
    uint8_t opc;

    system ("cls");

    printf ("\nMenu: ");
    printf ("\n\n1. Cargar Orden");
    printf ("\n2. Cargar reparado");
    printf ("\n3. Salir");
    scanf ("%d", &opc);

    return opc;
}

void crear_arch (void){
    FILE *fp;

    if ((fp=fopen ("../ordenes.dat","ab"))==NULL){
        printf ("\nNo se pudo crear el archivo.");
        getchar ();
    }

    fclose (fp);
}

void carga (void){
    repuestos_t aux, bf;

    FILE *fp;
    system ("cls");
    
    if ((fp=fopen ("../ordenes.dat","rb+"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        getchar ();
    }

    printf ("\nIngrese el Numero de Orden: ");
    scanf ("%ld",&aux.numeroDeOrden);
    
    fread (&bf,sizeof (repuestos_t),1,fp);

    if (bf.numeroDeOrden == aux.numeroDeOrden){
        printf ("\nNumero de orden existente.");
        getchar ();
    }
    else{
        printf ("\nIngrese el nombre del cliente: ");
        gets (aux.cliente);
        printf ("\nIngrese la descripcion de la falla: ");
        gets (aux.descripciondeFalla);
        printf ("\nIngrese el modelo: ");
        gets (aux.modelo);
        printf ("\nIngrese la fecha: ");
        gets (aux.fecha);
        printf ("\nIngrese la hora");
        gets (aux.hora);
        aux.estado = 'P';   //Pendiente de reparacion
    }

    fwrite (&aux,sizeof (repuestos_t),1,fp);

    fclose (fp);
}

void reparado (void){
    long aux;
    repuestos_t bf;

    FILE *fp;

    if ((fp=fopen ("../ordenes.dat","rb+"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        getchar ();
    }

    printf ("\nIngrese el Numero de Orden: ");
    scanf ("%ld",&aux);
    
    fread (&bf,sizeof (repuestos_t),1,fp); 

    while (!feof (fp)){
        if (bf.numeroDeOrden == aux)
            if (bf.estado == 'P'){
                bf.estado = 'R';
                printf ("\nSe cambio el estado de esa orden.");
                fseek (fp,(-1L)*(sizeof (repuestos_t)),1);
                fwrite (&bf,sizeof (repuestos_t),1,fp);
                getchar ();
            }
            else{
                printf ("\nYa se encuentra reparado.");
                getchar ();
            }
        else{
            printf ("\nNumero de orden no encontrado.");
            getchar ();
        }
    }

    fclose (fp);
}

struct pila * apilar (void){
    struct pila *p=NULL,*aux;
    struct lista *u=NULL,*del;

    u = ordenar (u);

    while (u){
        aux = (struct pila *)malloc (sizeof (struct pila));
        del = u;
        if (aux){
            aux->info = u->info;
            aux->l = p;
            p = aux;
        }
        u=u->l;
        free (del);
    }
}

struct lista * ordenar (struct lista *p){
    repuestos_t bf;
    struct lista *u,*r,*aux;

    FILE *fp;

    if ((fp=fopen ("../ordenes.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        getchar ();
    }

    fread (&bf,sizeof (repuestos_t),1,fp);

    while (!feof (fp)){
        aux = (struct lista *)malloc (sizeof (struct lista));

        if (aux){
            aux->info = bf;

            if (p == NULL){
                p=u=aux;
                u->l=NULL;
            }
            else{
                r=p;
                while (1){
                    if ((strcmp (r->info.fecha,aux->info.fecha))>0)
                        if ((strcmp (r->info.hora,aux->info.hora))>0){
                            aux->l = p;
                            p=aux;
                            break;
                        }   
                    while (r->l){
                        if((strcmp(r->l->info.fecha,aux->info.fecha))<0)
                            if((strcmp(r->l->info.hora,aux->info.hora))<0)
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
    }
}

void mostrar_pila (struct pila *p){
    struct pila *aux;

    system ("cls");
    printf("\n");
        
    do{
        aux=p;
        printf ("\n%-ld\t%-s\t%-s\t%s\t%s\t%s",p->info.numeroDeOrden,p->info.cliente,p->info.descripciondeFalla,p->info.modelo,p->info.fecha,p->info.hora);
        p=p->l;
        free(aux);
    }while(p!=NULL);
}
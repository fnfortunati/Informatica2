#include "../lib/lib.h"


void buscar (void){
    repuestos_t bf;
    struct cola *p = NULL, *u= NULL;
    FILE *fp;

    if ((fp=fopen ("../stock.dat","rb+"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        getchar ();
    }
    fread (&bf,sizeof (repuestos_t),1,fp);

    while (!feof (fp)){
        if (bf.partNumber == 1234){            
            if (bf.estatus == 'A'){  
                if (rev_bit (bf) == 1){
                    printf ("\n%-4d\t%-4d\t%-15s\t%-15s\t%c", bf.partNumber,bf.serialNumber,bf.descripcion,bf.ubicacion,bf.estatus);
                    bf.estatus = 'B';
                    fseek (fp,(-1L)*(sizeof (repuestos_t)),1);
                    fwrite (&bf,sizeof (repuestos_t),1,fp);
                    p= cargar (p,&u,bf);
                }
            }      
        }
        fread (&bf,sizeof (repuestos_t),1,fp);
    }
    crear_arch (&u);
}

uint8_t rev_bit (repuestos_t bf){
    if (bf.serialNumber & (1<<3) && bf.serialNumber & (1<<5))
        return 1;
    else
        return 0;
}

struct cola * cargar (struct cola *p, struct cola **u,repuestos_t bf){
    struct cola *aux;

    aux = (struct cola *) malloc (sizeof (struct cola));
    if (aux){
        aux->info = bf;
        if (p == NULL){
            p=*u=aux;
            p->ant = NULL;
            p->sig = NULL;
        }
        else{
            (*u)->sig=aux;
            aux->ant = *u;
            aux->sig=NULL;
            *u=aux;
        }
    }
    return p;
}

void crear_arch (struct cola **u){
    struct  cola *aux;
    repuestos_t bf;

    FILE *fp;
    
    if ((fp = fopen ("../inverso.dat","wb"))==NULL){
        printf ("\nNo se pudo abrir archivo.");
        getchar ();
    }

    aux = *u;
    
    do{
        bf = aux->info;
        fwrite (&bf,sizeof (repuestos_t),1,fp);
        aux = aux->ant;
    }while (aux != NULL);
}


void baja (void){
    repuestos_t bf;
    
    FILE *fp, *fpn;

    fp = fopen ("../stock.dat","rb");
    fpn = fopen ("../stock_n.dat","wb");

    if (!fp || !fpn){
        printf ("\nNo se pudo abrir archivo.");
        getchar ();
    }

    fread (&bf,sizeof (repuestos_t),1,fp);

    while (!feof (fp)){
        if (bf.estatus == 'A'){
            fwrite (&bf,sizeof (repuestos_t),1,fpn);
        }
        fread (&bf,sizeof (repuestos_t),1,fp);
    }

    fclose (fp);
    fclose (fpn);

    if (remove ("../stock.dat"))
        printf ("\nNo se pudo eliminar");

    if (rename ("../stock_n.dat","../stock.dat"))
        printf ("\nNo se pudo renombrar");
}

void mostrar_arch (void){
    repuestos_t bf;

    FILE *fp;

    if ((fp=fopen ("../inverso.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        getchar ();
    }

    fread (&bf,sizeof (repuestos_t),1,fp);

    while (!feof (fp)){
        printf ("\n%-4d\t%-4d\t%-15s\t%-15s\t%c", bf.partNumber,bf.serialNumber,bf.descripcion,bf.ubicacion,bf.estatus);
        fread (&bf,sizeof (repuestos_t),1,fp);
    }

    fclose (fp);
}
#include "../lib/lib.h"

void genero (void){
    FILE *fp;

    if ((fp=fopen ("../datos.dat","ab"))==NULL){
        printf ("\nNo se puede abrir archivo.");
        getchar();
    }
    fclose (fp);
}

//Cargo el archivo

void cargar_arch (void){
    FILE *fp;
    datos_t bf;
    long aux;
    uint8_t flag = 0;

    if ((fp=fopen ("../datos.dat","rb+"))==NULL){
        printf ("\nNo se puede abrir archivo.");
        getchar();
    }

    system ("cls");
    fflush(stdin);

    printf ("\nIngrese la clave del registro: ");
    scanf ("%ld",&aux);

    fread (&bf,sizeof (datos_t),1,fp);
    
    while (!feof(fp)){
        if (aux == bf.clave){
            flag = 1;
            printf ("\nEl registro ya existe.");
            getchar();
            break;
        }
        fread (&bf,sizeof (datos_t),1,fp);
    }

    if (flag == 0){
        bf.clave = aux;
        
        fflush(stdin);
        printf ("\nIngrese la descripcion del registro: ");
        scanf ("%s",&bf.c);
        fflush (stdin);
        printf ("\nIngrese el tipo del registro: ");
        scanf ("%c",&bf.tipo);

        bf.b='A';

        fwrite (&bf,sizeof (datos_t),1,fp);
    }

    fclose (fp);
}


//Busca los registros con el bit 4 en 1

struct pila * buscar_reg (void){
    datos_t bf;
    uint8_t pos=0,aux=0;
    clyp d;

    FILE *fp;
        
    struct pila *p=NULL;    
        
    if ((fp=fopen ("../datos.dat","rb"))==NULL){
        printf ("\nNo se puede abrir archivo.");
        getchar();
    }
    
    fread (&bf,sizeof(datos_t),1,fp);

    while (!feof(fp)){
        pos++;
        
        if (bf.tipo&(1<<4)){

            d.clave = bf.clave;
            d.pos = pos;
            strcpy (d.descrip,bf.c);

            p = cargar (p,d);
            
            aux++;
        }
            
        fread(&bf,sizeof(datos_t),1,fp);
    }

    fclose (fp);

    printf ("\nLa cantidad de registros es: %d", pos);

    printf ("\nLa cantidad de registros con bit 4: %d",aux);
    getchar();
    
    return p;
}

//Arma la pila

struct pila * cargar (struct pila *p,clyp d){
    struct pila *aux;

    aux = (struct pila *) malloc (sizeof (struct pila));
    
    if (aux){
        aux->d = d;
        aux->l=p;
        p=aux;    
    }

    return p;
}

//Muestro el archivo

void mostrar_arch (void){
    FILE *fp;
    datos_t bf;
    
    if((fp=fopen("../datos.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }

    fread (&bf, sizeof (datos_t),1,fp);
    printf("\nImpresion de archivo\n");
    while (!feof(fp)){
        printf ("\n%-ld\t%-s\t%d",bf.clave,bf.c,bf.tipo);
        fread (&bf, sizeof (datos_t),1,fp);
    }
    printf ("\n\n");
    fclose (fp);
}

//Muestro la pila

void mostrar_pila (struct pila *p){
    struct pila *aux;
    
    system ("cls");
    printf("\n");
        
    do{
        aux=p;
        printf ("\n%-ld\t%-s\t%d",p->d.clave,p->d.descrip,p->d.pos);
        p=p->l;
        free(aux);
    }while(p!=NULL);
}
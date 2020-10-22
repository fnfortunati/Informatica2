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
    long aux=0;
    uint8_t flag = 0;

    if ((fp=fopen ("../datos.dat","rb+"))==NULL){
        printf ("\nNo se puede abrir archivo.");
        getchar();
    }

    system ("cls");
    fflush (stdin);

    printf ("\nIngrese el id del registro: ");
    scanf ("%ld",&aux);

    fread (&bf,sizeof(long),1,fp);

    while (!feof(fp)){
        if (bf.clave == aux){
            flag = 1;
            printf ("\n\nEl registro ya existe.");
            getchar();
            break;
        }
        fread (&bf,sizeof(datos_t),1,fp);
    }

    if (flag == 0){
        bf.clave = aux;
        
        fflush (stdin);
        printf ("\nIngrese la descripcion del registro: ");
        gets (bf.c);
        fflush (stdin);
        printf ("\nIngrese el tipo de dato: ");
        scanf ("%d",&bf.tipo);
        bf.b = 'A';

        fwrite (&bf,sizeof(datos_t),1,fp);
        printf ("\nEscribi");
    }

    fclose (fp);
}

//Busca los registros con el bit 4 en 1

struct pila * buscar_reg (void){
        datos_t bf;
        uint8_t pos=0;
        clyp d;

        FILE *fp;
        
        struct pila *p;    
        
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

                p = cargar (d);
                break;
            }
            
            fread(&bf,sizeof(datos_t),1,fp);
        }

        fclose (fp);
}

//Arma la pila

struct pila * cargar (clyp d){
    struct pila *p=NULL, *aux;

    aux = (struct pila *) malloc (sizeof (struct pila));
    
    if (aux){
        aux->d = d;
        aux->l=p;
        p=aux;    
    }

    return p;
}


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
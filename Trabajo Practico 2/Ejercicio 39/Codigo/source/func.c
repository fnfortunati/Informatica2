#include "../lib/lib.h"

//Cargo la lista

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
        
        fflush (stdin);

        printf ("\n\nQuiere agregar a otra medicion ? 0-No   1-Si: ");
        scanf ("%d", &opc);

    }while (opc != 0);

    return p;
}

//Creo el archivo

void archivo (struct lista *p){
    FILE *fp;
    struct lista *aux;
    pot_t bf;
    
    bf.id = 0;

    if ((fp=fopen ("../potencia.dat","wb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        return;
    }

    while (p){
        aux = p;

        bf.id++;
        strcpy(bf.dato.desc,p->dato.desc);
        bf.dato.potencia=p->dato.potencia;
        bf.dato.estado=p->dato.estado;
        bf.b = 'A';
        fseek(fp,0L,2);

        fwrite (&bf, sizeof (pot_t),1,fp);
        
        p=p->l;
        free (aux);
    }
    fclose (fp); 

}

//Muestro el archivo

void mostrar_arch (void){
    FILE *fp;
    pot_t bf;
    
    if((fp=fopen("../potencia.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }

    fread (&bf, sizeof (pot_t),1,fp);
    
    system ("cls");

    while (!feof(fp)){
        printf ("\n%d\t%-20s\t%d\t%d",bf.id,bf.dato.desc,bf.dato.potencia,bf.dato.estado);
        fread (&bf, sizeof (pot_t),1,fp);
    }
    printf ("\n\n");
    fclose (fp);
}
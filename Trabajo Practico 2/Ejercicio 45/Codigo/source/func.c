#include "../lib/lib.h"

int cuenta_datos (void){
    repuestos_t  d;
    uint8_t c=0;

    FILE *fp;
    
    if((fp=fopen("../../../Ejercicio 41/Codigo/stock.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }

    fread (&d,sizeof (repuestos_t),1,fp);
    while (!feof(fp)){
        c++;
        fread (&d,sizeof (repuestos_t),1,fp);
    }
    fclose (fp);
    
    return c;
}

repuestos_t * bajar_arch (void){
    repuestos_t *d;
    uint8_t cant;

    FILE *fp;

    if((fp=fopen("../../../Ejercicio 41/Codigo/stock.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }
    
    cant = cuenta_datos ();

    //Bajo el archivo a memoria
    d=(repuestos_t *) malloc (sizeof (repuestos_t) * cant);
    fread (d,sizeof (repuestos_t),cant,fp);

    fclose(fp);

    return d;
}

//Funcion para armar la pila

struct pila * cargar (repuestos_t *d){
    struct pila *p = NULL, *aux;
    uint8_t cant,i;

    cant = cuenta_datos ();
    for (i=0; i<=cant; i++){
        aux = (struct pila *) malloc (sizeof (struct pila));
        if (aux){
            aux->pieza = d[i];
            aux->sacar = 'N';
            aux->l=p;
            p=aux;    
        }
    }
    return p;
}

struct cola * buscar (extraccionRepuestos_t pieza ,struct pila *p, struct cola *c){
    struct pila *aux;
    uint8_t ret = 0,falt;
    aux = p;

    while (aux){
        while (ret < pieza.cantidad)
            if (pieza.repuesto.partNumber == aux->pieza.partNumber){
                aux->sacar = 'S';
                ret++;
                aux = aux->l;
            }
    }

    if (pieza.cantidad != ret){
        falt = pieza.cantidad - ret;
        c = arm_cola (c,pieza.repuesto.partNumber,falt);
    }

    return c;
}

struct cola * arm_cola (struct cola *c,long pn, uint8_t falt){
    struct cola *aux, *u;

    aux = (struct cola *) malloc (sizeof (struct cola));

    if (aux){
        aux->pieza.repuesto.partNumber = pn;
        aux->pieza.cantidad = falt;

        if (c == NULL){
            c=u=aux;
            c->l = NULL;
        }
        else{
            u->l = aux;
            aux->l = NULL;
            u = aux;
        }
    }

    return c;
}

void act_arch (struct pila *p){
    struct pila *aux;

    FILE *fp;

    if((fp=fopen("../../../Ejercicio 41/Codigo/stock.dat","wb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }

    aux = p;

    while (p){
        if (p->sacar != 'S')
            fwrite (&p->pieza,sizeof (repuestos_t),1,fp);
        p = p->l;
        free (aux);
    }
   
}
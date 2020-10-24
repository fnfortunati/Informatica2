#include "../lib/lib.h"

//Busco la primera palabra y la invierto

char * primera (char *p){
    uint8_t i,cant;
    char palabra [60]=" ";

    for (i=0;*(p+i)!= ' '; i++)
        palabra[i] = p[i];
    
    p = palabra;

    printf ("\nLa primera palabra es: %s\n",p);

    //Falta terminar
    
    return p;
}

//Busco el registro por el id

void buscar_reg (void){
    uint8_t id;
    pot_t bf;
    char *p;

    FILE *fp;

    fflush (stdin);
    printf ("\nIngrese el id: ");
    scanf ("%d",&id);

    //Codigo para buscar el id

    if ((fp=fopen ("../../../Ejercicio 39/Codigo/potencia.dat","rb"))==NULL){
        printf ("\nNo se puede abrir el archivo.");
        return;
    }

    fseek (fp,(long)sizeof (pot_t)*(id-1),0);
    fread (&bf, sizeof (pot_t),1,fp);
    
    if (bf.id == id){    
        p=primera (bf.dato.desc);
        printf ("\n%d",bf.dato.estado);
        bf.dato.estado = bf.dato.estado ^(1<<3);
        printf ("\n%d",bf.dato.estado);
    }
    else{
        printf ("\nNo se encontro registro");
        getchar();
    }

    fclose (fp);

    actualizar_arch (bf,id);
}

//Actualizo el archivo "potencia.dat"

void actualizar_arch (pot_t bf, uint8_t id){
    pot_t aux;

    FILE *fp;

    if ((fp=fopen ("../../../Ejercicio 39/Codigo/potencia.dat","rb+"))==NULL){
        printf ("\nNo se puede abrir el archivo.");
        return;
    }

    fseek (fp,(1L)*sizeof(pot_t)*(id-1),0);
    fread (&aux,sizeof(pot_t),1,fp);

    strcpy (aux.dato.desc,bf.dato.desc);
    aux.dato.estado = bf.dato.estado;

    fseek (fp,(-1L)*sizeof(pot_t),1);
    fwrite (&aux,sizeof(pot_t),1,fp);

    fclose (fp);
}

//Reviso Bit 0 y 2 en "1"

void rev_bit (void){
    struct pila *p=NULL;

    pot_t bf;

    FILE *fp;

    if ((fp=fopen ("../../../Ejercicio 39/Codigo/potencia.dat","rb"))==NULL){
        printf ("\nNo se puede abrir el archivo.");
        return;
    }

    fread (&bf,sizeof (pot_t),1,fp);

    while (!feof (fp)){
        if ((bf.dato.estado&(1<<2))&&(bf.dato.estado&(1<<0))){  //Lo podia hacer tmb como (bf.dato.estado&5)
            p=cargar_pila (p,bf.dato.potencia);
        }
        else{
            arch_sec (bf.dato);
        }
    }

    fclose (fp);
}

//Armo la pila

struct pila * cargar_pila (struct pila *p,unsigned char pot){
    struct pila *aux;

    aux = (struct pila *) malloc (sizeof (struct pila));
    if (aux){
        aux->potencia = pot;
        aux->l=p;
        p=aux;    
    }

    return p;
}

//Creo y cargo el archivo "salida.dat"

void arch_sec (medicion_t reg){

    FILE *fp;

    if ((fp=fopen ("../salida.dat","ab"))==NULL){
        printf ("\nNo se puede abrir el archivo.");
        return;
    }

    fwrite (&reg,sizeof (medicion_t),1,fp);

    fclose (fp);
}
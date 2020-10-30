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
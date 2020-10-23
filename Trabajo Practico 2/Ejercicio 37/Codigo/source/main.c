#include "../lib/lib.h"

int main (void){
    uint8_t opc;
    datos_t bf;
    long aux;
    uint8_t flag;

    FILE *fp;

    struct pila *p;
/*
    //Genero el archivo
    
    genero();

    //Cargo el archivo

    do{
        cargar_arch();
        fflush (stdin);
        printf ("\n\nQuiere agregar a otro registro ? 0-No   1-Si: ");
        scanf ("%d", &opc);
    }while(opc!=0);
*/


    //Busco el registro

    p = buscar_reg();

//    mostrar_arch ();

    mostrar_pila (p);
    
    return 0;
}
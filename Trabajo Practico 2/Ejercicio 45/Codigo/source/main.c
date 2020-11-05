#include "../lib/lib.h"

int main (void){
    uint8_t opc;
    extraccionRepuestos_t aux;
    repuestos_t *d;
    struct pila *p;
    struct cola *c = NULL;

    //Bajo el archivo a memoria
    d = bajar_arch ();

    //Armado de pila
    p = cargar (d);

    do{
        system ("cls");
        printf ("\nIngrese el numero de parte: ");
        scanf ("%ld",aux.repuesto.partNumber);
        printf ("\nIngrese la cantidad: ");
        scanf ("%d",aux.cantidad);
        c = buscar (aux,p,c);

        printf ("\nDesea retirar otro repuesto ? 0- No 1- Si");
        scanf ("%d",&opc);
    }while (opc !=0);

    act_arch (p);
}
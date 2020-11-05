#include "../lib/lib.h"

int main (void){
    uint8_t opc;
    extraccionRepuestos_t pieza;

    do{
        opc = menu ();
        switch (opc){
        case 1:
            printf ("\nIngrese el Nro de Parte del Repuesto: ");
            scanf ("%ld",&pieza.repuesto.partNumber);
            printf ("\nIngrese la descripcion: ");
            gets (pieza.repuesto.descripcion);
            printf ("\nIngrese la cantidad: ");
            scanf ("%d",&pieza.cantidad);
            cargar (pieza);
            break;

        }
    }while (opc !=2);
}
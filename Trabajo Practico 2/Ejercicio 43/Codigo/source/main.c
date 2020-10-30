#include "../lib/lib.h"

int main (void){
    uint8_t opc;

    struct pila *p;

    crear_arch ();
    
    do{
        opc = menu ();      
        switch (opc){
        case 1:
            carga();
            break;
        case 2:
            reparado();
            break;
        }
    }while (opc != 3);

    p = apilar ();

    mostrar_pila (p);

    return 0;
}
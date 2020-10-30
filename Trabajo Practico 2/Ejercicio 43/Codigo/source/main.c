#include "../lib/lib.h"

int main (void){
    uint8_t opc;

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
}
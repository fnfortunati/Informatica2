#include "../lib/lib.h"

int main (void){   
    cantidad_t cant;
    estados_t estado = espera;
    uint8_t flag = 0;

    estados_t (*f_estado[])(cantidad_t *, uint8_t *) = {f_espera,f_ent,f_sal,f_aviso};
    
	f_inicio(&cant);
    
	while (1){
        if (flag == 0)
            printf ("\nAutos en el estacionamiento: %d\n\n",cant.cant);
        estado = (*f_estado[estado])(&cant,&flag);
    }

    return 0; 
}

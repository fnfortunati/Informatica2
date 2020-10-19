#include "../lib/lib.h"

//Funcion para inicializar la maquina de estados

void f_inicio (cantidad_t *cant){
    parConfig ("../config.conf",cant);
}


//Funcion de espera

estados_t f_espera (cantidad_t *cant,uint8_t *flag){
    estados_t estado = espera;
    uint8_t ent, sal;

    if (*flag == 0){
        printf ("En espera.\n\n");
        *flag = 1;
    }
    
    if (kbhit ()){
        ent = b_ent();
        sal = b_sal();
        *flag = 0;
    }
    

    if (ent == 1 && cant->cant < cant->cant_set-cant->deltaC)
        estado = barr_ent;

    if (ent == 1 && cant->cant >= (cant->cant_set-cant->deltaC))
        estado = aviso;
    
    if (sal == 1 && cant->cant >0)
        estado = barr_sal;
    
    return estado;
}

//Funcion barrera entrada

estados_t f_ent (cantidad_t *cant, uint8_t *flag){
    estados_t estado = barr_ent;
    uint8_t ent = 1;

    if (*flag == 0){
        *flag = 1;
    }
    
    if (kbhit()){
        ent = b_ent();
        *flag = 0;
    }

    if (ent == 0){
        estado = espera;
        cant->cant++;
    }
    return estado;
}

//Funcion barrera salida

estados_t f_sal (cantidad_t *cant, uint8_t *flag){
    estados_t estado = barr_sal;
    uint8_t sal = 1;

    if (*flag == 0){
        printf ("En salida.\n\n");
        *flag = 1;
    }

    if (kbhit()){
        sal = b_sal();
        *flag = 0;
    }

    if (sal == 0){
        estado = espera;
        cant->cant--;
    }
    return estado;
}

//Funcion mensaje de aviso

estados_t f_aviso (cantidad_t *cant, uint8_t *flag){
    estados_t estado = aviso;
    uint8_t ent = 1;

    if (*flag == 0){
        printf ("No hay espacio en la cochera actualmente, pruebe en unos minutos.\n\n");
        *flag = 1;
    }

    if (kbhit()){
        ent = b_ent();
        *flag = 0;
    }

    if (ent == 0)
        estado = espera;
    
    return estado;
}

//Funciones para simulacion de los sensores de barrera

//Sensor barrera de entrada

uint8_t b_ent (void){
    uint8_t aux;

    do {
        printf ("Auto en la entrada ? ");
        scanf ("%d", (int*) &aux);

        if (aux > 1 || aux < 0)
            printf ("Error valor ingresado, debe ser 1 o 0 \n");

    }while (aux > 1 || aux < 0 );
    return aux;
}
 
//Sensor barrera de salida

uint8_t b_sal (void){
    uint8_t aux;

    do {
        printf ("Auto en la salida ? ");
        scanf ("%d", (int*) &aux);

        if (aux > 1 || aux < 0)
            printf ("Error valor ingresado, debe ser 1 o 0 \n");
    
    }while (aux > 1 || aux < 0 );

    return aux;
}

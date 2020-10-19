#include "../lib/lib.h"


//Funcion para la carga de parametros de configuracion

void parConfig (char *filename,cantidad_t *cantidad){
    FILE *conf;
    char cadena [40],*key,*val;
    char variables [3][15]= {"set","deltaC","cant"},i;

    if ((conf = fopen (filename,"rt"))== NULL){
        printf ("No se encontro archivo de configuracion\n");
    }
    fgets (cadena,40,conf);
    
    do{
        key =cadena;
        if ((*key)!= '#' && strlen (key) >=0){
            val = getKey (key);
                     
            for (i=0; i<3; i++){
                if (!strcmp (key,variables [i])){
                switch (i) {
                    case 0: 
                        cantidad->cant_set=atoi (val);
                        break;
                    case 1: 
                        cantidad->deltaC = atoi (val);
                        break; 
                    case 2: 
                        cantidad->cant = atoi (val);
                        break;
					}
                }         
            }    
        }
        fgets (cadena,40,conf);
    }while (!feof (conf));
}

char *getKey (char *key){
    char i=0;

    while (*(key+i)!=' '){
        i++;
    }
    *(key+i)=0;
    return key+i+1;
}

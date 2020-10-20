#include "../lib/lib.h"

int cuenta_datos (void){
    persona_t  d;
    uint8_t c=0;

    FILE *fp;
    
    if((fp=fopen("../../../Ejercicio 35/Codigo/contactos.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }

    fread (&d,sizeof (persona_t),1,fp);
    while (!feof(fp)){
        c++;
        fread (&d,sizeof (persona_t),1,fp);
    }
    fclose (fp);
    
    return c;
}

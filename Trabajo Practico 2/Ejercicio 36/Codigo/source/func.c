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

persona_t * bajar_arch (void){
    persona_t *d;
    uint8_t cant;

    FILE *fp;

    if((fp=fopen("../../../Ejercicio 35/Codigo/contactos.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }
    
    cant = cuenta_datos ();

    //Bajo el archivo a memoria
    d=(persona_t *) malloc (sizeof (persona_t) * cant);
    fread (d,sizeof (persona_t),cant,fp);

    fclose(fp);

    return d;
}

//Creo la lista

struct lista * cargar (persona_t *d){
    struct lista *p=NULL,*u=NULL,*aux,*r;
    uint8_t i,cant;

    cant = cuenta_datos();

    for(i=0;i<cant;i++){
        aux=(struct lista *)malloc (sizeof(struct lista));

        if (aux){
            strcpy (aux->dato.apellido,d[i].apellido);
            strcpy (aux->dato.nombre,d[i].nombre);
            aux->dato.edad = d[i].edad;
            strcpy (aux->dato.telefono,d[i].telefono);
            strcpy (aux->dato.mail,d[i].mail);

            if (p==NULL){
                p=u=aux;
                u->l=NULL;
            }
            else{
                r=p;
                while (1){
                    if (strcmp(r->dato.apellido,aux->dato.apellido)>0){
                        aux->l=p;
                        p=aux;
                        break;
                    }
                    while (r->l) {
                        if(strcmp(r->l->dato.apellido,aux->dato.apellido)<0)
                            r=r->l;
                        else
                            break;
                    }
                    if (r==u){
                        u->l=aux;
                        u=aux;
                        u->l=NULL;
                        break;
                    }
                    aux->l=r->l;
                    r->l=aux;
                    break;
                }
            }

        }
    }

    return p;
}

//Creo el archivo

void archivo (persona_t bf){
    FILE *fp;

    persona_t aux;
    uint8_t flag=0;

    if ((fp=fopen ("../contactos_ordenados.dat","ab"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        return;
    }

    fclose (fp);

    if ((fp=fopen ("../contactos_ordenados.dat","rb+"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
        return;
    }

    fread (&aux, sizeof (persona_t),1,fp);

    while (!feof (fp)){
        if (strcmp (aux.apellido,bf.apellido)==0)
            flag = 1;
        fread (&aux, sizeof (persona_t),1,fp);
    }

    if (flag == 0)
        fwrite (&bf, sizeof (persona_t),1,fp);

    fclose (fp);
}

//Muestro el archivo con los datos ordenados

void mostrar_arch (void){
    FILE *fp;
    persona_t bf;
    
    if((fp=fopen("../contactos_ordenados.dat","rb"))==NULL){
        printf ("\nNo se pudo abrir el archivo.");
    }

    fread (&bf, sizeof (persona_t),1,fp);
    
    while (!feof(fp)){
        printf ("\n%-10s\t%-10s\t%2d\t%-15s\t%-30s",bf.apellido,bf.nombre,bf.edad,bf.telefono,bf.mail);
        fread (&bf, sizeof (persona_t),1,fp);
    }
    printf ("\n\n");
    fclose (fp);
}

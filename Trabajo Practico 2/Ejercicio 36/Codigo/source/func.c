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

struct lista * cargar (persona_t *d,uint8_t cant){
    struct lista *p=NULL,*u=NULL,*aux,*r;
    uint8_t i;

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

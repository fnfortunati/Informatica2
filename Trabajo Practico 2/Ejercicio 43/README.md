__EJERCICIO 43__:

El servicio técnico de __*CosmeFulanito*__ recibe órdenes de trabajo diarias. Las mismas son cargadas en un archivo secuencial por el personal de recepción bajo la siguiente estructura de datos:
 ```c
typedef struct{
    long numeroDeOrden;
    char cliente[40];       
    char descripciondeFalla[200];        
    char modelo[65];
    char fecha[10];
    char hora[10];
    char estado;
}repuestos_t;
```
Se pide:
- Hacer una pila con las órdenes de trabajo de forma tal que la más vieja sea la última en cargarse.
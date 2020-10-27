- __EJERCICIO 41__: 

El depósito de la empresa __*CosmeFulanito*__ necesita cargar su stock de repuestos en forma ordenada. Para dicha tarea se solicitó categorizar a los respuestos bajo la siguiente estructura de datos:

 ```c
typedef struct{
    long partNumber;
    long serialNumber;
    char descripcion[40];       
    char ubicacion[100];        
}repuestos_t;
```
Los repuestos no están ordenados, se solicita cargarlos en una lista, la cual ordene por descripción a los repuestos para luego guardarlos en un archivo de *stock* con organización secuencial.
    
> - Imprimir en pantalla la lista con cada inserción. 
> - El archivo se generará cuando el usuario decide no cargar mas productos.
__EJERCICIO 44__:

El servicio técnico utiliza la pila generada en el ejercicio 43 en su labor diaria. Cada técnico toma una tarea de la pila y genera un orden de extracción de repuestos al depósito. Para optimizar los viajes al depósito se arma una lista con los repuestos que cada orden necesita utilizando la siguiente estructura:

```c
typedef struct{
    repuestos_t repuesto;        
    int cantidad;
}extraccionRepuestos_t;
```
Se pide cargar la lista de repuestos solicitados por los técnicos. Tener en cuenta que varios técnicos pueden necesitar la misma parte, y en esos casos se debe incrementar la cantidad pedida en la lista. 
## TRABAJO PRÁCTICO 2

Los siguientes ejercicios seran resueltos en cada una de las carpetas correspondientes:

- __EJERCICIO 35__: 

    Hacer un programa que tome los datos de contacto de una persona (Nombre, Apellido, edad, teléfono, mail) y los cargue, en forma directa, en una pila de memoria dinámica. Imprimir en pantalla y cargar en un archivo llamado "contactos.dat", de organización secuencial, los registros ingresados por el usuario si la persona tiene una edad mayor a 21 años.

- __EJERCICIO 36__:

    Hacer un programa que lea al archivo "contactos.dat" creado en el __Ejercicio 35__ y crear una lista, en memoria dinámica, ordenada alfabéticamente. Una vez creada la lista guardarla en un archivo de organización directa llamado "contactos_ordenados.dat" imprimiendola en pantalla.

- __EJERCICIO 37__:

    Existe un archivo llamado "datos.dat", de tipo binario, cuya organización es secuencial. Los datos están organizados según la siguiente estructura:   
                                                                                 
    ```c
    struct d{                                                                                            
    long clave; //Clave o Id del registro
    
    char d[30]; // Descripcion                                                                                          
    unsigned char tipo; //Tipo de datos como entero sin signo                                                                                                                                            
    char b; //'A':Alta 'B':Baja                                                                                                                                                                          
    }
    ```
                            
    Se Pide:
    Realizar una funciún que pase como parámetro la clave, entre otros parámetros, y apile dos valores, la Clave y su posición física respecto 
    al archivo (registro 1, 2, etc), si es que el campo tipo tiene el bit 4 con valor 1. En caso de no encontrarlo mostrar por pantalla "Registro no encontrado".
    La función debe devolver el puntero de pila.
    Realizar el main con varias llamadas a dicha función y proceder a mostrar las descripciones del archivo, mediante la pila como acceso directo, __NO USAR VARIABLES GLOBALES__.             
- __EJERCICIO 38__:

    Hacer una cola con los valores muestreados de un cuarto de ciclo de una señal sinusoidal, en 8 bits, para luego recorrerla y recomponer la señal completa. Las muetras deberán ir de 127 a -127 utilizando el bit más significativo en 1 para los valores negativos y en 0 para los valores positivos. Imprimir en pantalla los valores.
- __EJERCICIO 39__:

    Hacer un programa que tome los datos de medición de potencia, cargados por el usuario, de un sistema de medición a distancia.

    Los datos que cargará el usuario tienen la siguiente estructura:
    ```c
        char desc[60];
        unsigned char potencia;
        unsigned int estado;
    ```
    Donde estado es la multiplicación del valor ASCII de la primer letra de la descripción por la potencia. 
    Los datos cargados se deberán guardar en una lista ordenada, de mayor a menor, del valor de potencia. Una vez finalizada la carga guardar los datos en un archivo de organización directa llamado "potencia.dat" imprimiendo en pantalla los datos.
   
- __EJERCICIO 40__:

     Utilizando el archivo “potencia.dat” creado en el __Ejercicio 39__, realizar una función que pase como parámetro, entre otros datos, la clave del registro (id). 
     
     La función ubicará el registro correspondiente al id pasado como parámetro, y utilizando punteros imprimirá la primera palabra del campo "desc" en forma inversa, además cambiará el estado del bit 3 para luego actualizar el archivo. Además, se agregará a una pila la potencia cuando los bits 0 y 2, del campo estado, estén encendidos, en caso contrario se agregará el registro al archivo “salida.dat” de organización secuencial.

     - __EJERCICIO 41__: 

    El depósito de la empresa __*CosmeFulanito*__ necesita cargar su stock de repuestos en forma ordenada. Para dicha tarea se solicitó categorizar a los respuestos bajo la siguiente estructura de datos:
     ```c
    typedef struct{
        long partNumber;
        long serialNumber;
        char descripcion[40];       
        chat ubicacion[100];        
    }repuestos_t;
    ```
    Los repuestos no están ordenados, se solicita cargarlos en una lista, la cual ordene por descripción a los repuestos para luego guardarlos en un archivo de *stock* con organización secuencial.
    
    > - Imprimir en pantalla la lista con cada inserción. 
    > - El archivo se generará cuando el usuario decide no cargar mas productos.
- __EJERCICIO 42__:

     El proveedor de repuestos de __*CosmeFulanito*__ informó que una partida de repuestos salió con falla y debe ser devuelta. Para identificar la partida, el proveedor indicó que la falla fue en el partNumber: 1234 que tiene números de serie con el bit 3 y 5 en 1.

    Para estas tareas se solicita:
    - Hacer una cola con todos los registros fallados
    - Realizar la baja física a todos los repuestos fallados 
    - Crear un archivo donde se vuelque el contenido de la cola en orden inverso.

- __EJERCICIO 43__:

    El servicio técnico de __*CosmeFulanito*__ recibe órdenes de trabajo diarias. Las mismas son cargadas en un archivo secuencial por el personal de recepción bajo la siguiente estructura de datos:
     ```c
    typedef struct{
        long numeroDeOrden;
        char cliente[40];       
        char descripciondeFalla[200];        
        char modelo[65];
        char fecha[10];
        char hora[10];
    }repuestos_t;
    ```
    Se pide:
    - Hacer una pila con las órdenes de trabajo de forma tal que la más vieja sea la última en cargarse.

- __EJERCICIO 44__:

    El servicio técnico utiliza la pila generada en el ejercicio 43 en su labor diaria. Cada técnico toma una tarea de la pila y genera un orden de extracción de repuestos al depósito. Para optimizar los viajes al depósito se arma una lista con los repuestos que cada orden necesita utilizando la siguiente estructura:

    ```c
    typedef struct{
        repuestos_t repuesto;        
        int cantidad;
    }extraccionRepuestos_t;
    ```

    Se pide cargar la lista de repuestos solicitados por los técnicos. Tener en cuenta que varios técnicos pueden necesitar la misma parte, y en esos casos se debe incrementar la cantidad pedida en la lista. 
 

- __EJERCICIO 45__:
    
    La lista creada en el ejercicio 44 es procesada por el depósito. 
    Para dicha tarea se pide hacer un programa que:
    - Descuente las cantidades solicitadas del archivo de stock, creado en el __Ejercicio 41__.
    - Hacer una cola con los repuestos en los que no se encontró stock suficiente para poder notificar a los clientes la demora de la reparación. 

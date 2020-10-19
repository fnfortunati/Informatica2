# TP. Máquina de Estados - Control de Estacionamiento

## Máquina de estado de control de estacionamiento

### Memoria descritiva: Memoria descritiva:

Mi sistema representa un control de acceso para un estacionamiento, con cantidad máxima de vehículos y un delta configurable. Se registra la cantidad de autos que ingresando por medio de dos sensores, y se activaran dos barreras (entrada y salida respectivamente); tanto los sensores como las barreras seran emulados.

El sistema queda al aguardo de que alguno de los sensores de las barreras se active; y de acuerdo a si la cantidad de autos que hay en el estacionamiento es mayor o menor la cantidad seteada menos el delta activara la barrera de entrada (si es menor) o la barrera de salida (si es mayor). A su vez la barrera de salida no tiene una limitación, ya que todos los autos que entren tienen que salir.

### Diagrama:

![./recursos/Esquema.png](https://github.com/fnfortunati/Trabajo_Practico/blob/master/recursos/Esquema.PNG)

**REFERENCIA**

- **SE** = Sensor Barrera de Entrada
- **SS** = Sensor Barrera de Salida
- **B_E** = Barrera de Entrada
- **B_S** = Barrera de Salida
- **MSG** = Mensaje de aviso
- **CS** = Cantidad de Vehículos Permitidos
- **DC** = Delta de Cantidad de Vehículos Permitidos

**Sensor NO Activado** = "0"

**Sensor Activado** = "1"
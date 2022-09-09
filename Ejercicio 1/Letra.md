## Emails	

Nombre de archivo: ejercicio1.cpp/Ejercicio1.java

### Letra

Se tiene una base de datos de usuario identificados por e-mail pero se empezo a notar de que existen usuarios duplicados (comparten el mismo e-mail) por lo cual se quiere calcular cuantos usuarios reales existen.
Input
La primera línea de la entrada contiene un número entero positivo N (2 ≤ N ≤ 10^5), el número de usuarios acutales del sistema.

Las siguientes N lineas contienen los email actuales del sistema
Salida
Imprime el único número entero: la cantidad real de usuarios (sin repetidos).

### Restricciones
Utilizar una tabla de hash cerrado.
Resolver en orden temporal: O(N) promedio, siendo N la cantidad de usuarios.

### Ejemplos de entrada y salida

#### Entrada
5
abc@abc.com
cba@cba.com
abc@abc.com
abc@abc.com
aaa@aaa.com 

#### Salida
3


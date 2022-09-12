## Emails	

Nombre de archivo: ejercicio2.cpp/Ejercicio2.java

### Letra

Se desea ordenar un conjunto de números enteros, no acotados. Se solicita que implemente un algoritmo basado en el uso de un heap, en particular mediante el uso de la técnica de “heapificación” (heapify en inglés).

### Input

La primera línea de la entrada contiene un número entero positivo N (2 ≤ N ≤ 10^5), el largo del conjunto de números.
Las siguientes N líneas contienen los números del conjunto.

### Salida

Imprime N líneas con los números ordenados de menor a mayor

### Restricciones

Utilizar la técnica heapify.
Resolver en orden temporal: O(N log N) promedio, siendo el tamaño del conjunto.
Resolver en orden espacial auxiliar (sin contar el array de números): O(1)

### Ejemplos de entrada y salida

#### Entrada
5  
10  
4  
7  
42  
3  

#### Salida
3  
4  
7  
10  
42  
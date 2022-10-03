## Del más al menos	

Nombre de archivo: ejercicio5.cpp/Ejercicio5.java

### Letra

Dado un grafo dirigido, retornar un listado con sus vértices ordenados decrecientemente por grado de incidencias. En el listado, deberá incluirse el número de vértice seguido por su cantidad de aristas incidentes. En caso de haber dos o más vértices que tengan igual grado de incidencia, deberán ordenarse decrecientemente por número.

### Input

Formato de Grafos

### Salida

V líneas de formato <vértice> <grado de incidencia> (sin los símbolos < y >).

### Restricciones

Resolver en orden temporal: O(V Log V) peor caso, siendo V la cantidad de vértices (sin tener en cuenta la lectura de datos).

### Ejemplos de entrada y salida

#### Entrada
4  
5  
1 2 10  
1 3 20  
2 1 40  
4 2 50  
4 3 60  


#### Salida
3 2  
2 2  
1 1  
4 0  
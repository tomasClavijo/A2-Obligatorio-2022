## Triconexo	

Nombre de archivo: ejercicio4.cpp/Ejercicio4.java

### Letra

Dado un grafo no dirigido, indicar si el mismo es triconexo. Un grafo es triconexo cuando todo par de vértices están conectados por al menos tres caminos disjuntos. Dicho de otra forma, un grafo es triconexo cuando luego de eliminar dos vértices cualesquiera, el grafo continúa siendo conexo.

### Input

Formato de Grafos

### Salida

1 en caso que el grafo sea triconexo. 0 en caso contrario.

### Restricciones

Resolver en orden temporal: O(V2 * (V + E)) peor caso, siendo E la cantidad de aristas y V la cantidad de vértices.

### Ejemplos de entrada y salida

#### Entrada
4  
6  
1 2 10  
1 3 20  
1 4 30  
2 3 40  
2 4 50  
3 4 60  

#### Salida
1  

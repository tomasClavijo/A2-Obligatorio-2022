## ACM-E	

Nombre de archivo: ejercicio3.cpp/Ejercicio3.java

### Letra

Dado un grafo no dirigido y disperso, se desea obtener un árbol de cubrimiento mínimo del mismo, el cual debe excluir a ciertos vértices indicados.

### Input

Inicialmente, respeta el Formato de Grafos. Luego, posee una línea con un entero indicando la cantidad de vértices a ignorar, seguido de dichos vértices.

### Salida

Línea indicando la cantidad de aristas, seguido por una línea por cada arista. 
Por cada arista se imprime de forma que el vertice de menor número vaya primero.
El orden de toda la lista esta dado por número de vertice.

### Restricciones

Resolver en orden temporal: O(E log V) promedio, siendo E la cantidad de aristas y V la cantidad de vértices.

### Ejemplos de entrada y salida

#### Entrada
4  
6  
1 2 10  
1 3 200  
1 4 1891  
2 3 40  
2 4 50  
3 4 60  
1  
2  

#### Salida
2  
1 3 200  
3 4 60  

## Máxima sumatoria de tres pilas

Nombre de archivo: ejercicio7.cpp/Ejercicio7.java

### Letra

Dado tres stacks de números positivos se quiere saber cual es la sumatoria máxima que pueden llegar a tener en común los tres stack/pilas (individualmente). 

### Input

La primera línea (N) es la cantidad de elementos de la primer pila, las siguientes N líneas son los elementos de la pila. La siguiente línea (M) es la cantidad de elementos de la segunda pila, las siguientes M líneas son los elementos de la pila. La siguiente línea (P) es la cantidad de elementos de la tercer pila, las siguientes P líneas son los elementos de la pila.

### Salida

Contendrá 1 sola línea con la sumatoria máxima obtenida.

### Restricciones

Solo pueden ser retirados los topes de las pilas.  
O(n+m+p) temporal (con n, m y p los tamaños originales de las pilas).  
O(n+m+p) espacial.  
Debe realizarse con la táctica greedy.  

### Ejemplos de entrada y salida

#### Entrada
**5**  
3  
2  
1  
1  
1  
**3**  
4  
3  
2  
**4**  
2  
5  
4  
1  

#### Salida
5  

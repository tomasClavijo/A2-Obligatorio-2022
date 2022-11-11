## SUBCONJ. DE SUMA M (BT)

Nombre de archivo: ejercicio9.cpp/Ejercicio9.java

### Letra

Dados un conjunto C de N>0 enteros positivos estrictos Ki, es decir, Ki>0 para todo i con 1 ≤ i ≤ N, y un entero positivo Mi, se desea saber si existe un subconjunto S de C que sumados den como resultado Mi, pudiendo repetir tantas veces como se desee los elementos. 
Se desea resolver el mismo problema anterior pero con algunos cambios.

### Input

La primera línea N indica cuántos elementos tiene C. Las siguientes N líneas son los elementos. Luego, sigue un número M que es una cota de todos los casos Mi que finalizan a la entrada. La siguiente línea indica la cantidad P de casos de prueba. Los siguientes P números indican los casos Mi con 1≤i≤P para los cuales se desea conocer si existe S.

Por ejemplo: 
Si C={3,34,4,12,5,2} y M=9 entonces sí existe S={4,5}.  
Si C={3} y M=9 entonces sí existe S={3,3,3}.

### Salida

La salida contendrá P líneas indicando la mínima cantidad de elementos de la sumatoria, o en caso de que no exista un 0.

### Restricciones

1. Se debe realizar con la táctica de backtracking.
2. No tiene restricciones temporales ni espaciales.
3. De ser posible realizar una poda, debe realizarla.
4. La salida dejará de ser 1 a 0 a:
- 0 si no existe un subconjunto que cumpla las condiciones.
- La mínima cantidad de elementos de la sumatoria.

### Ejemplos de entrada y salida

#### Entrada  

#### Salida

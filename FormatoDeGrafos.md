# Formato de entrada de ejercicios de grafos

Todos los ejercicios de grafos tendrán la misma codificación para los grafos. Es decir, una parte del formato de entrada, la que corresponde a la información del grafo será siempre igual. A continuación se describe:  

V  
E  
v1 w1 [c1]  
v2 w2 [c2]  
…   
vi wi [ci]  
…   
vE wE [cE]  

Cada grafo comienza con la cantidad de vértices, V. Los vértices siempre serán números, a menos que se especifique lo contrario. Por ejemplo, si V=3, entonces los vértices serán: {1, 2, 3} (siempre serán numerados a partir de 1).  

La siguiente línea corresponde a la cantidad de aristas, E. Las siguientes E líneas en el formato v w c corresponden a las aristas (v,w) con costo c si el grafo es ponderado, o en el formato v w, correspondiente a la arista (v,w) si no es ponderado. Es decir, c es opcional ([c]).   

El grafo será dirigido o no, dependiendo el problema en particular. En caso de ser no dirigido solo solo se pasará un sentido de la arista, es decir, (v,w) pero no (w,v) (queda implícito). Por ejemplo:  

2  
1  
1 2  

Representa al grafo completo de dos vértices y aristas: {(1,2), (2,1)}.
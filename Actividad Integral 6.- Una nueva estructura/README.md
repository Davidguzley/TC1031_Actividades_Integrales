# Actividad Integral 6

# Counting sort

## Descripcion:
El counting sort es un algoritmo de ordenamiento, el cual ordena cualquier cosa a partir del conteo de numero de elementos contenidos de cada clase.
Inicialmente se recibe un vector para posteriormente encontrar el intervalo en el que estan los datos a ordenar. Posteriormente se crea un vetor compuesto con ceros con la longitud de dicho intervalo. Finalmente se recorren los elementos a ordenar y se cuenta el numero de apariciones de cada elemento para guardarlo en el vector creado. Por lo que solo resta recorrer este vector para tener todos los elementos ordenados.

## Uso:
Este algoritmo se puede realizar para todos los casos en los que se necesite ordenar y saber cuantas veces aparece cada elelmento. Como por ejemplo contar y ordenar todos los votos de unos candidatos, como es el caso de este programa, contar la cantidad de nucleotidos de una cadena de ADN, Contar y ordenar monedas y billetes,etc. Esto sucede gracias a que todos sus algoritmos pueden trabajar con enteros, flotantes y strings como por ejemplo palabras, dinero, numeros de cuenta, etc.

![alt tag](https://github.com/Davidguzley/TC1031_Actividades_Integrales/blob/master/Actividad%20Integral%206.-%20Una%20nueva%20estructura/Example-of-counting-sort.png)

## ¿Que se hizo?
Se hizo un programa de votaciones el cual recibe un archivo de texto con registros o logs.
Cada registro del archivo de texto llamado "votaciones.txt" contiene el voto de una persona con el siguiente formato:
Nombre / ApellidoPaterno / ApellidoMaterno / numeroCandidato o voto.
Con esto se almacenan los votos de los votantes y el del usuario por medio de una pregunta. Posteriormente se cuentan y ordenan todos los votos y se muestra los resultados
Finalmente en el arhivo de texto "ordenados.txt" se almacenan el resultado de las votaciones y del ordenamiento hecho en el main del programa.

**nota:Los casos de prueba se corren en el main por medio de la funcion del archivo "casosPrueba.txt"

## Análisis de complejidad temporal

### main.cpp
El main comienza abriendo el archivo txt ("votaciones.h"), haciendo uso de un while se aigna a una varible a cada atributo del txt y guarda el voto de cada persona en el vector votos, ya que solo recorre n pasos hasta haber leido cada linea del archivo de textosu complejidad temporal para el peor de los casos es O(n) o lineal para el peor de los casos.
Una vez conseguido el vector con todos los votos del txt se pregunta y se despliega en pantalla los candidatos, para que  el suario vote y se guarde su voto en el vector. Fialmente ese vector es pasado a la funcion countSort() para contar cada elemento y ordenar el vector.
Para poder imprimir los datos ordenados y el resultado de las votaciones utilicé las funciones toStringCount() y toStringArray(). Por lo que su complejidad temporal es O(1) o lineal para el peor de los casos.
Ya mostradoslos resultados el codigo prosigue a guardarlos en un archivo de texto llamado ("resultados.txt"). Por lo que la complejidad es la misma que la anterior.

### counting.h
#### countSort
El algoritmo su entrada para la ordenación de conteo consiste en una colección de n elementos, cada uno de los cuales tiene una clave de número entero no negativo cuyo valor  máximo es como máximo k, por lo que su complejidad temporal es O(n+k) para el peor de los casos, esto significa que es mejor que O(n) devido a que el numero de pasos esta deliminato por el valor maximo o k que tiene los datos del arreglo.

#### toStringCount
El algoritmo recorre n pasos debido a un ciclo while que correra hasta haber encontrado el numero de apariciones de cada uno de los candidatos. Devolviendo en un string los votos de cada candidato, por lo que su complejidad temporal es O(n) o lineal para el peor de los casos debido a la compejidad O(n) del ciclo.

### toStringArray
El algoritmo recorre n pasos, ya que usa un ciclo while que recorre cada valor del arreglo data hasta llegar a count, mientras que en cada ciclo almacena en un string el numero de cuenta de cada cliente, por lo que su complejidad temporal es O(n) o lineal para el peor de los casos debido a la compejidad O(n) del ciclo.

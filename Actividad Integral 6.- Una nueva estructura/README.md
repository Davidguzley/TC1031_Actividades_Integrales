# Actividad Integral 6

# Counting sort

## Descripcion:
El counting sort es un algoritmo de ordenamiento, el cual ordena cualquier cosa a partir del conteo de numero de elementos contenidos de cada clase.
Inicialmente se recibe un vector para posteriormente encontrar el intervalo en el que estan los datos a ordenar. Posteriormente se crea un vetor compuesto con ceros con la longitud de dicho intervalo. Finalmente se recorren los elementos a ordenar y se cuenta el numero de apariciones de cada elemento para guardarlo en el vector creado. Por lo que solo resta recorrer este vector para tener todos los elementos ordenados.

## Uso:
Este algoritmo se puede realizar para todos los casos en los que se necesite ordenar y saber cuantas veces aparece cada elelmento. Como por ejemplo contar y ordenar todos los votos de unos candidatos, como es el caso de este programa, contar la cantidad de nucleotidos de una cadena de ADN, Contar y ordenar monedas y billetes,etc.

![alt tag](https://raw.githubusercontent.com/A00572858/TC1031_Integral5/main/graph2.png)

## ¿Que se hizo?
Se hizo un programa de votaciones el cual recibe un archivo de texto con registros o logs.
Cada registro del archivo de texto llamado "votaciones.txt" contiene el voto de una persona con el siguiente formato:
Nombre / ApellidoPaterno / ApellidoMaterno / numeroCandidato o voto.
Con esto se almacenan los votos de los votantes y el del usuario por medio de una pregunta. Posteriormente se cuentan y ordenan todos los votos y se muestra los resultados
Finalmente en el arhivo de texto "ordenados.txt" se almacenan el resultado de las votaciones y del ordenamiento hecho en el main del programa.

**nota: ** Los casos de prueba se corren en el main por medio de la funcion del archivo "casosPrueba.txt"

## Análisis de complejidad temporal

### main.cpp
El main comienza abriendo el archivo txt ("cuentas.h"), haciendo uso de un while se aigna a una varible a cada atributo del txt y estas se almacenan dentro de un objeto como propiedades o atributos para posteririormente
guardar cada objeto dentro del vector v a medida que corre el ciclo, ya que solo recorre n pasos hasta haber leido cada linea del archivo de texto
su complejidad temporal para el peor de los casos es O(n) o lineal para el peor de los casos.
Una vez conseguido el vector con todos los objetos generados por el txt este es pasado como parametro a la funcion ordenaBurbuja() para ser ordenada en base a un atributo llamado dinero.
Para poder imprimir los datos ordenados utilicé un ciclo for con complejidad temporal O(n) o lineal para el peor de los casos para que se imprimiera con mostrar() todos los objetos del vector, este proceso se podria tomar prueba solamente ya que es solo para verificar que la funcion halla ordenado todos los datos bien.
Ya mostrados los datos ordenados el codigo prosigue a guardar en un archivo de texto llamado ("ordenados.txt") los resultaodos del ordenamiento por medio de el ordenamiento e insercion de cada atributo
de los objetos del vector mediante sus getters y un ciclo for con complejidad temporal O(n) o lineal para el peor de los casos para recorrer todo el vector.
Por su parte se prensentan en consola tres instrucciones para que el usuario pueda definir un rango de cantidad de dinero en cuentas para poder buscarlo.
Su cantidad de rango inicial es asignada en r_inicial y la de rango final en r_final para poder usadas como parametros para la funcion busqBinaria. La funcion obtiene los valores de las pocisiones
las cuales son usadas en un ciclo for con complejidad temporal O(n) o lineal para el peor de los casos para desplegar en consola los registros correspondientes a las entradas del usuario.

### sorts.h
#### ordenaBurbuja
El algoritmo ordena los numeros de un vector en orden ascendente mediante dos ciclos for que estan sujetos entre si, en los objetos la cantidad de dinero mas grande e intercambiando su posicion con la funcion swap
por el que se encuentra en la ultima posicion, repitiendo el proceso con cada uno de los valores restantes del vector excluyendo los ya acomodados.
Debido a los n pasos que le toma a cada ciclo for su complijidad es n(n+1/2) y su complejidad temporal es O(n^2) o cuadratico para el peor de los casos.
La eleccion de este algoritmo fue debido a que solo se necesita el vector que le pasamos como parametro en la funcion y la funcion swap para poder trabajar con el algoritmo,
por lo que su complejidad espacial sera O(1) o constante ya que se genera muy poco espacio en la memoria. Asi es como decidi priorizar la complejidad espacial a la temporal ya que la cantidad
la cantidad de n pasos que le llava al algoritmo acomodar el vector no son muchos debido a su cantidad de elementos y cada uno de estos elementos almacena un objeto.

#### busqBinaria
El algoritmo busca la posicion de un numero o la posicion en donde deberia estar este en un vector ordenado en orden ascendente, para ello utiliza un ciclo while que generara ciclos cuando
bot(primera pocision del vector) sea menor o igual a top(ultima posicion del vector) a medida que en cada ciclo mid divide el vector entre 2 y se busca el numero mediante condiciones repecto a mid
Por lo que su complejidad temporal es O(log(n)) o logaritmico para el peor de los casos. Asimismo gracias a lo mencionado al principio de la explicacion de este algoritmo responde al porque de su
seleccion para el programa

# ACERCA DEL PROYECTO
## Descripcion:
Este proyecto esta compuesto de 4 actividades integrales que cumplen 4 usos distintos para manejar la informacion, la primera su objetivo es hacer un add y ordenar las cuentas, la segunda es hacer un remove de las cuentas, la tercera es hacer un find y la cuarta es hacer un update.
Para ello el programa utiliza informacion de cuentas de clientes de un banco almacenada en un archivo de texto con registros o logs
y mediante estructuras de datos usa dicha informacion para implementar algoritmos que ayuden al usuario a encontrar, modificar u organizar la informacion de manera mas sencilla.
Cada registro del archivo de texto llamado "cuentas.txt" contiene una cuenta bancaria de un cliente con el siguiente formato:
no.cuenta(8 digitos) / Nombre / ApellidoPaterno / ApellidoMaterno / DineroCuenta.

**nota: Los casos de prueba se corren en el main por medio de las funciones del archivo "casosPrueba.h". Por lo que se le solicita al usuario escribir "no" cuando se le pregunte si desea modificar o borrar algo para correr todos los casos de prueba de manera correcta.**

# ACTIVIDAD INTEGRAL 5 (ULTIMA ACTIVIDAD INTEGRAL)
## ¿Que se hizo?
Para esta entrega se implento la estructura hash simple con sus respectivos casos de prueba debido a que en la mayoria de sus metodos la complejidad temporal es de O(1) en la mayoria de los casos y O(n) para el peor de los casos,  pero esto muy raro ya que solo sucede cuando la tabla hash se encuentra saturada, ademas resulta de gran utilidad esta estructura ya que se utilizo la lista creada del avance anterior contenida en el archivo (cuentasArbol.txt), donde los numeros de cuenta de cada cliente se encuentra almacenada. Una vez implementado la tabla hash simple, se añadio al codigo poder modificar los datos personales de cualquier numero de cuenta que desee el usuario encargado del banco para actualizar la informacion de los clientes.
Finalmente la estructura implementada en este avance es guardada en el archivo (cuentasHash.txt).


## Análisis de complejidad temporal

### main.cpp
Para esta entrega el main abre el archivo (cuentasHash.txt) ya que unicamente se encuentran aqui los numeros de cuenta existentes, haciendo uso de un while dentro de otro while y un for, se toman las numeros de cuenta del txt para escoger sus objetos correspondientes del vector creado del primer avance, posteririormente a medida que corre los ciclos, mediante la funcion put(Key, Value) se añade la Key que es el numero de cuenta y el Value que es el objeto con la informacion de ese numero de cuenta a la tabla hash simple.
se guarda cada numero de cuenta dentro de un arbol heap , ya que solo se recorre n*n pasos hasta haber leido la unica linea del archivo de texto y cada uno de los valores del vector
su complejidad temporal para el peor de los casos es O(n^2) o cuadratico.
Una vez conseguido la tabla hash con todos los valores dados por el txt, se imprime en consola el string generado por la la funcion toString() para ver lo contenido en la tabla hash.
Posteriormente este string es almcenado en el archivo txt (cuentasHash.txt), como solo toma un paso guardar el string en el archivo de texto su compejidad temporal para el peor de los casos es O(1) o constante.
Finalmente el main pregunta al usuario si quiere ingresar un numero de cuenta para actualizar sus datos mediante la funcion pruebaSetCuenta(HashTable<Key, Value> &hash, string llave), debido a que solo se revisa por medio de ifs la respuesta del usuario su complejidad temporal es O(1) o constante para el peor de los casos.

### hash.h
#### put
Gracias a la funcion indexOf() se puede saber el indice o pocision de la llave. A partir de ello lo que se hace es agregar la llave y el valor pasados como parametro de la funcion, y en caso de colision se movera a la siguiente posicion. Por lo que su complejidad temporal para el peor de los casos segun la literatura es O(n) o lineal, pero solo en caso de que la tabla hash se encuentra saturada, pero para la mayoria de los casos su complejidad temporal es O(1) o constante, debido a que solo se agregaran valores y llaves a los indices de la tabla.

#### toString
El algoritmo recorre n pasos, ya que usa un ciclo while que recorre cada contenido de los arreglos keys y values data hasta llegar a size, mientras que en cada ciclo almacena en un string el numero de cuenta y la informacion personal de cada cliente, por lo que su complejidad temporal es O(n) o lineal para el peor de los casos. 

#### get
Devueleve el Value de una Key de la tabla, gracias a la funcion indexOf() que devuelve el indice o pocision de esa Key, solo se saca su Value, por lo que su complejidad temporal para el peor de los casos es O(1) o constante para el peor de los casos.

#### contains
Simplemente si la funcion indexOf() devuelve un -1 significa que la llave pasada coo parametro de esta funcion, no se encuentra en la tabla hash simple, por lo solo le toa un paso hacer esto, su complejidad temporal para el peor de los casos es O(1) o constannte para el peor de los casos.

### casosPrueba.h
#### pruebaSetCuenta
Esta funcion solo manda a llamar las funciones correspondientes de el archivo hash.h y cuentas.h para actualizar los datos de una cuenta, por lo que su complejidad temmporal para el peor casos es o(1) o constante para el peor de los casos.



# ACTIVIDAD INTEGRAL 3
## ¿Que se hizo?
Para esta entrega se implento la estructura de arbol heap con sus respectivos casos de prueba debido a que en la mayoria de sus metodos la complejidad temporal es de O(log n) y O(1) para el peor de los casos, ademas resulta de gran utilidad esta estructura ya que se utilizo la lista creada del avance anterior contenida en el archivo (cuentasLista.txt) en donde los numeros de cuenta de cada cliente se encuentra almacenada. Una vez implementado el arbol heap, se añadio al codigo poder buscar de manera sencilla cualquier numero de cuenta que desee el usuario encargado del banco para validar si una persona es cliente o no del banco.
Finalmente la estructura implementada en este avance es guardada en el archivo (cuentasArbol.txt).


## Análisis de complejidad temporal

### main.cpp
Para esta entrega el main abre el archivo (cuentasLista.txt) ya que unicamente se encuentran aqui los numeros de cuenta, haciendo uso de un while dentro de otro while se aigna una varible para los numeros de cuenta del txt, posteririormente a medida que corre el ciclo mediante la funcion push(T val)
se guarda cada numero de cuenta dentro de un arbol heap , ya que solo se recorre n pasos hasta haber leido la unica linea del archivo de texto
su complejidad temporal para el peor de los casos es O(n) o lineal.
Una vez conseguido el arbol con todos los valores dados por el txt, se imprime en consola el string generado por la la funcion toString() para ver lo contenido en el arbol.
Finalmente este string es almcenado en el archivo txt (cuentasLista.txt), como solo toma un paso guardar el string en el archivo de texto su compejidad temporal para el peor de los casos es O(1) o constante.
Gracias a esto el main pregunta al usuario si deseea buscar una cuenta para que ingrese un numero de cuenta y lo busque pormedio de la funcion pruebaBusqSecuencial(Heap<T> &arbol, string num), debido a que solo se revisa por medio de ifs la respuesta del usuario la complejidad temporal de este proceso es O(1) o constante para el peor de los casos

### heap.h
#### push
El algoritmo recibe como parametro un valor T para ser agregado a la fila priorizada, haciendo uso de un ciclo while cada valor que se quiera insertar sera de izquierda a derecha y por niveles en el arbol, checando que el hijo siempre sean mas chico que su padre, por lo que su complejidad temporal es O(log n), es decir, logaritmica, para el peor de los casos.

#### toString
El algoritmo recorre n pasos, ya que usa un ciclo while que recorre cada valor del arreglo data hasta llegar a count, mientras que en cada ciclo almacena en un string el numero de cuenta
de cada cliente, por lo que su complejidad temporal es O(n) o lineal para el peor de los casos debido a la compejidad O(n) del ciclo. 

#### busqSecuencial
El algoritmo busca un numero un valor T dentro del arbol recorriendo n pasos, ya que usa un ciclo for que va de i=0 hasta count (numero de elementos que hay en dicho del arbol), devolviendo strue si se ha encontrado o false si no se ha encontrado, por lo que su complejidad temporal es O(n) o lineal para el peor de los casos.

### casosPrueba.h
#### pruebaBusqSecuencial
Esta funcion solo manda a llamar las funciones correspondientes de el archivo heap.h y cuentas.h para realizar la busqueda de una cuenta, por lo que su complejidad temmporal para el peor casos es o(1) o constante para el peor de los casos.



# ACTIVIDAD INTEGRAL 2
## ¿Que se hizo?
Se realizaron las correcciones pertinentes de la entrega pasada como añadir mas comentarios para que la persona pueda entender mas el codigo,
actualizacion del README, descripciones de los archivos al inicio
de estos y un archivo llamado "casosPrueba.h" para correr casos de prueba en el main si lo desea el usuario.
Mientras que en esta entrega se añadio al programa la funcionalidad de leer el archivo de los registros ordenados para almacenarlos en una lista ligada simple
y guardar de esa lista los numeros de cuenta de los clientes en un archivo llamado "cuentasLista.txt", ademas de poder elimiar un elemento de la lista para borrar una cuenta.

## Análisis de complejidad temporal

### main.cpp
Para esta entrega el main abre el archivo ("ordenados.txt") ya que las cuentas ya se encuentran ordenadas, haciendo uso de un while se aigna una varible a cada atributo del txt y estas se almacenan dentro de un objeto como propiedades o atributos para posteririormente
guardar cada objeto dentro de una lista ligada simple llamada "lista" a medida que corre el ciclo mediante la funcion add(T val), ya que solo se recorre n pasos hasta haber leido cada linea del archivo de texto
su complejidad temporal para el peor de los casos es O(n) o lineal.
Una vez conseguido la lista con todos los objetos generados por el txt se imprime en consola el string generado de la funcion toString() para ver lo contenido de cada objeto de la lista visualizandolos por el atributo cuentaNum ya que este es unico de cada cuenta.
Finalmente este to string es almcenado en el archivo txt (cuentasLista.txt), por lo tanto como solo toma un paso guardar el string en el archivo de texto su compejidad temporal para el peor de los casos es O(1) o constante.

### list.h
#### add
El algoritmo recorre n pasos, ya que usa un ciclo while que recorrera los n elementos de la lista hasta llegar a su ultima posicion
y añadira el elemento pasado como parametro de la funcion en la lista,
ademas en el caso de contar con una lista vacia la funcion addFirst añadira este valor comp primer elemento de la lista,
por lo que su complejidad temporal es O(n) o lineal para el peor de los casos debido a la compejidad O(n) del ciclo y la complejidad O(1) de la funcion addFirst.

#### remove
El algoritmo recorre n pasos, ya que recibe como parametro un valor entero como indice, el cual es buscado mediante un while que recorre la lista hasta hallar su posicion dentro de la lista, se remuve el elemento contenido en esa posicion y se acomoda la lista. La funcion removeFirst es utilizada en caso de que el indice sea cero, se remuve el primer elemento contenido en la lista o se arroja un aviso en caso de estar ya vacia. Con esto podemos decir qu la complejidad temporal del algoritmo es O(n) o lineal para el peor de los casos debido a la complejidad O(n) del ciclo y la complejidad O(1) de la funcion removeFirst.

#### find
El algoritmo busca la posicion de un numero dentro de una lista recorriendo n pasos, ya que usa un ciclo while que que recorre la lista hasta hallar su posicion, devolviendo su numero de posicion o -1 si no se ha encontrado, por lo que su complejidad temporal es O(n) o lineal para el peor de los casos debido a que solo se recorre n elementos de la lista.

#### toString
El algoritmo recorre n pasos, ya que usa un ciclo while que recorre toda la lista hasta llegar a nulo, mientras que en cada ciclo almacena en un string el numero de cuenta
de cada cliente u objeto Cuenta, por lo que su complejidad temporal es O(n) o lineal para el peor de los casos debido a la compejidad O(n) del ciclo. 

### casosPrueba.h
#### pruebaDelete
Esta funcion solo manda a llamar las funciones correspondientes de el archivo list.h y cuentas.h para reover una cuenta, por lo que su complejidad temmporal para el peor casos es o(1) o constante para el peor de los casos.



# ACTIVIDAD INTEGRAL 1
## ¿Que se hizo?
Un programa capaz de realizar busquedas de un vector ordenado en un rango especificado por el usuario del dinero contenido en cada cuenta solicitandole donde quiere que inicie y donde quiere que termine dicho rango y poder desplegar los registros contenidos en dicho rango.
El acrchivo "clase.h" que contiene una clase para poder asignar un sitio a cada atributo del txt y de esta manera poder manejarlos de manera independiente.
Los unicos metodos que posee son getters para la obtencion del valor de cualquier atributo de los objetos que se instancien
y una funcion llamada mostrar() para imprimir los atributos de un objeto en consola.
Ademas en el arhivo de texto "ordenados.txt" se almacenan el resultado del ordenamiento hecho en el main del programa.

## Análisis de complejidad temporal

### main.cpp
El main comienza abriendo el archivo txt ("cuentas.txt"), haciendo uso de un while se aigna a una varible a cada atributo del txt y estas se almacenan dentro de un objeto como propiedades o atributos para posteririormente
guardar cada objeto dentro del vector v a medida que corre el ciclo, ya que solo recorre n pasos hasta haber leido cada linea del archivo de texto
su complejidad temporal para el peor de los casos es O(n) o lineal.
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
Por lo que su complejidad temporal es O(log(n)) o logaritmico para el peor de los casos. Asimismo gracias a lo mencionado al principio de la explicacion de este algoritmo responde al porque de su seleccion para el programa

### casosPrueba.h
#### pruebaRango
Esta funcion solo manda a llamar las funciones correspondientes de el archivo sorts.h y cuentas.h para realizar una busqueda por un rango definido por el usuario del dinero de las cuentas, por lo que su complejidad temmporal para el peor casos es o(1) o constante para el peor de los casos.

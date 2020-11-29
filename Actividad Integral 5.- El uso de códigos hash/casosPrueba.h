/* casosPrueba.h
 *
 *  Created on: 21/09/2020
 *      Author: David Guzman Leyva
 * Description: sirve para correr funciones de casos de prueba
 */

#ifndef CASOSPRUEBA_H_
#define CASOSPRUEBA_H_

#include "cuenta.h"
#include "sorts.h"
#include "list.h"
#include "heap.h"
#include "hash.h"

using namespace std;

//Prueba un rango de busqueda
template <class T>
void pruebaRango(vector<T> &v, int r_inicial, int r_final) {
	int inicio, final;
  inicio = busqBinaria(v, r_inicial);
  final= busqBinaria(v, r_final);
  //Se muestra el resultado
  cout<< "\n" << "Resultado" << "\n";
  for (int i = inicio; i <= final; i++) {
      cout << v[i].mostrar() << endl;
  }
}

//Corre los casos de prueba de busqueda por rango
template <class T>
void casosRango(vector<T> &v) {
  cout << "\n" << "-Prueba 1 de busqueda binaria: inputs 0 y 11" << endl;
  pruebaRango(v, 0, 11);

  cout << "\n" << "-Prueba 2 de busqueda bnaria: inputs 10 y 1000000" << endl;
  pruebaRango(v, 10, 1000000);

  cout << "\n" << "-Prueba 3 de busqueda binaria: inputs 708 y 708" << endl;
  pruebaRango(v, 708, 708);
}

template <class T>
void pruebaDelete(List<T> &lista, string cuentaNum){
  int index;
  index = lista.find(cuentaNum);
  //Se realiza la eliminacion
  if(index != -1){
    cout << "Cuenta " << lista.remove(index).getCuentaNum() << " removida." << endl;
    cout << "Lista con numeros de cuenta:" << endl;
    cout << lista.toString() << endl;
  }
  else{
    cout << "El numero de cuenta no existe." << endl;
  } 
}

template <class T>
void casosDelete(List<T> &lista){
  cout << "\n" << "-Prueba 1 eliminar cuenta: 01010101" << endl;
  pruebaDelete(lista, "01010101");

  cout << "\n" << "-Prueba 2 eliminar cuenta: 00000000" << endl;
  pruebaDelete(lista, "00000000");

  cout << "\n" << "-Prueba 3 eliminar cuenta: 85094325" << endl;
  pruebaDelete(lista, "85094325");

}

template <class T>
void pruebaBusqSecuencial(Heap<T> &arbol, string num) {
  if(arbol.busqSecuencial(num)){
      cout << "Numero de cuenta encontrado." << endl;
  }
  else{
    cout << "El numero de cuenta no existe." << endl;
  }
}

template <class T>
void casosBusqSecuencial(Heap<T> &arbol) {
  cout << "\n" << "-Prueba 1 de busqueda secuencial: input 00045678 == True" << endl;
  pruebaBusqSecuencial(arbol, "00045678");

  cout << "\n" << "-Prueba 2 de busqueda secuencial: input 70649583 == True" << endl;
  pruebaBusqSecuencial(arbol, "70649583");

  cout << "\n" << "-Prueba 3 de busqueda secuencial: input 01010102 = False" << endl;
  pruebaBusqSecuencial(arbol, "01010102");
}

template <class Key, class Value>
void pruebaSetCuenta(HashTable<Key, Value> &hash, string llave){
  Cuenta setCuenta;
  if(hash.contains(llave)){
    cout << "El numero de cuenta existe." << endl;
    //Se obtiene la cuenta del cliente de la tabla hash
    setCuenta = hash.get(llave);
    //Se actualiza la cuenta
    setCuenta.actualizarDatos();

    //Se actualiza y sela tabla hash
    hash.put(setCuenta.getCuentaNum(), setCuenta);
    cout << "\n" << "Tabla hash actualizada............" << endl;
    cout << hash.toString() <<endl;
  }
  else{
    cout << "El numero de cuenta no existe." << endl;
  }
}

template <class Key, class Value>
void casoSetCuenta(HashTable<Key, Value> &hash){
  cout << "\n" << "-Prueba 1 de setDatosCuenta: cuentaNum 00045678" << endl;
  pruebaSetCuenta(hash, "00045678");

  cout<< "\n" << "-Prueba 2 de setDatosCuenta: cuentaNum 70649583" << endl;
  pruebaSetCuenta(hash, "70649583");

  cout<< "\n" << "-Prueba 3 de setDatosCuenta: cuentaNum 01010102" << endl;
  pruebaSetCuenta(hash, "01010102");
}

#endif
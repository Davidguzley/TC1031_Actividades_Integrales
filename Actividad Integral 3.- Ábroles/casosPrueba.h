/* casosPrueba.h
 *
 *  Created on: 21/09/2020
 *      Author: David Guzman Leyva
 * Description: sirve para correr funciones de casos de prueba
 */

#ifndef CASOSPRUEBA_H_
#define CASOSPRUEBA_H_

#include "sorts.h"
#include "cuenta.h"
#include "heap.h"

using namespace std;

//Prueba un rango de busqueda
template <class T>
void pruebaRango(vector<T> &v, int r_inicial, int r_final) {
	int inicio, final;
  inicio = busqBinaria(v, r_inicial);
  final= busqBinaria(v, r_final);
  for (int i = inicio; i <= final; i++) {
      v[i].mostrar();
  }
}

//Corre los casos de prueba de busqueda por rango
template <class T>
void casosRango(vector<T> &v) {
  cout<< "Prueba 1 de busqueda binaria: inputs 0 y 11" << endl;
  pruebaRango(v, 0, 11);

  cout<< "\n" << "Prueba 2 de busqueda bnaria: inputs 10 y 1000000" << endl;
  pruebaRango(v, 10, 1000000);

  cout<< "\n" << "Prueba 3 de busqueda binaria: inputs 708 y 708" << endl;
  pruebaRango(v, 708, 708);
}

template <class T>
void pruebaBusqSecuencial(Heap<T> &arbol, string num) {
  if(arbol.busqSecuencial(num)){
      cout << "Numero de cuenta encontrado" << endl;
  }
  else{
    cout << "El numero de cuenta no existe" << endl;
  }
}

template <class T>
void casosBusqSecuencial(Heap<T> &arbol) {
  cout<< "Prueba 1 de busqueda secuencial: input 00045678 == True" << endl;
  pruebaBusqSecuencial(arbol, "00045678");

  cout<< "\n" << "Prueba 2 de busqueda secuencial: input 70649583 == True" << endl;
  pruebaBusqSecuencial(arbol, "70649583");

  cout<< "\n" << "Prueba 3 de busqueda secuencial: input 01010102 = False" << endl;
  pruebaBusqSecuencial(arbol, "01010102");
}


#endif
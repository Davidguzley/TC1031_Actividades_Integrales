/*
 * sorts.h
 *
 *  Created on: 21/09/2020
 *      Author: David Guzman Leyva
 *   Descripcion: Archivo con funciones de busqueda
 *   y ordenamiento.
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include "cuenta.h"

using namespace std;

//Intercambia los valores de dos variables
template <class T>
void swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

//Algoritmo de ordenamiento que ordena un vector
template <class T>
vector<T> ordenaBurbuja(vector<T> &v) {
	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j].getDinero() > v[j + 1].getDinero()) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

//Busca un numero dentro de un vector y devuelve su posicion
template <class T>
int busqBinaria(vector<T> &v, int num) {

	int mid;
	int bot = 0;
	int top = v.size() - 1;

	while (bot <= top) {
		mid = (top + bot) / 2;
		if (num == v[mid].getDinero()) {
			return mid;
		} else if (num <= v[mid].getDinero()) {
			top = mid - 1;
		} else if (num >= v[mid].getDinero()) {
			bot = mid + 1;
		}
	}
	return bot-1;
}

#endif
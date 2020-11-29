/*
 * heap.h
 *
 *  Created on: 21/10/2020
 *      Author: David Guzman Leyva
 *  Description: Archivo para crear arboles heap
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T>
class Heap {
private:
	T *data; //En donde se almacenan los datos
	int tam; //cantidad maxima de datos
	int count; //Cantidad actual de datos
	int parent(int) const; //Papa
	int left(int) const; //Hijo
	int right(int) const; //Hijo
	void swap(int, int); 
  void heapify(int); //acomoda la fila
public:
	Heap(int); //constructor
	void push(T); //añade valor
	string toString() const; //guarda fila en string
  int size() const; //cuantos valores estan almacenados?
  bool busqSecuencial(T); //Busca un numero de cuenta bancaria
};

template <class T>
Heap<T>::Heap(int sze) { //constructor
	tam = sze;
	data = new T[tam]; //arreglo creado
	count = 0;
}

template <class T>
int Heap<T>::parent(int pos) const {
	return (pos - 1) / 2;
}

template <class T>
int Heap<T>::left(int pos) const { 
	return ((2 * pos) + 1);
}

template <class T>
int Heap<T>::right(int pos) const {
	return ((2 * pos) + 2);
}

//Funciones para acomodar e intercambiar valores del arbol
template <class T>
void Heap<T>::swap(int i, int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}
template <class T>
void Heap<T>::heapify(int pos) {
	int le = left(pos);
	int ri = right(pos);
	int min = pos;
	if (le <= count && data[le] < data[min]) {
		min = le;
	}
	if (ri <= count && data[ri] < data[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

//Añade un valor al arbol
template <class T>
void Heap<T>::push(T val){
	int pos;
	pos = count;
	count++;

	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

//Devuelve cuantos valores estan almacenados
template <class T>
int Heap<T>::size() const{
	return count;
}

//Guarda en un string el arbol
template <class T>
string Heap<T>::toString() const {
	stringstream aux;
  for (int i = 0; i < count; i++) {
		if (i != 0) {
			aux << ",";
		}
    aux << data[i];
	}
	return aux.str();
}

//Busca un valor en el arbol
template <class T>
bool Heap<T>::busqSecuencial(T val) {

	for (int i = 0; i < count; i++) {
		if (val == data[i]) {
			return true;
		}
	}
	return false;
}

#endif
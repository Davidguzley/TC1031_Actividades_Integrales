/*
 * heap.h
 *
 *  Created on: 29/11/2020
 *      Author: David Guzman Leyva
 *  Description: Archivo para crear tablas hash simples
 */

#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class Key, class Value>
class HashTable {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	HashTable(unsigned int, Key, unsigned int (*f) (const Key)); //Constructor
	~HashTable(); //Destructor
	int put(Key, Value); // Agrega o actualiza a la tabla
	bool contains(const Key) const; //Busca una llae en la tabla
	Value get(const Key); //Devueleve el valor de una llave de la tabla
	string toString() const; //Pasa a string la tabla
};

template <class Key, class Value>
HashTable<Key, Value>::HashTable(unsigned int sze, Key init, unsigned int (*f) (const Key)){
	size = sze;
	keys = new Key[size];
	if (keys == 0) {
		cout<<"Sin memoria"<<endl;
	}
	initialValue = init;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = init;
	}
	values = new Value[size];
	if (values == 0) {
		cout<<"Sin memoria"<<endl;
	}
	/*for (int i = 0; i  < sze; i++){
        values[i] = 0;
    }*/

	func = f;
	count = 0;
}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable() {
	delete [] keys;
	keys = 0;
	delete [] values;
	values = 0;
	size = 0;
	func = 0;
	count = 0;
}

template <class Key, class Value>
long HashTable<Key, Value>::indexOf(const Key k) const {
	unsigned int i, start;

	start = func(k) % size;
  i = func(k) % size;
	do {
		if (keys[i] == k) {
			return i;
		}
		i = (i + 1) % size;
	} while (start != i);
	return -1;
}

template <class Key, class Value>
int HashTable<Key, Value>::put(Key k, Value v) {
	unsigned int i, start;
	long pos;

	pos = indexOf(k);
	if (pos != -1) {
		values[pos] = v;
		return pos;
	}

	start = func(k) % size;
  i= func(k) % size;
	do {
		if (keys[i] == initialValue) {
			keys[i] = k;
			values[i] = v;
			count++;
			return i;
		}
		i = (i + 1) % size;
	} while (start != i);
	return i;
}

template <class Key, class Value>
bool HashTable<Key, Value>::contains(const Key k) const {
	long pos;

	pos = indexOf(k);
	return (pos != -1);
}

template <class Key, class Value>
Value HashTable<Key, Value>::get(const Key k) {
	unsigned int i, start;
	long pos;

	pos = indexOf(k);
	if (pos != -1) {
		return values[pos];
	}
	else{
    cout<<"llave incorrecta"<<endl;
  }
}

template <class Key, class Value>
string HashTable<Key, Value>::toString() const {
	stringstream aux;

	for (unsigned int i = 0; i < size; i++) {
		aux << "[ " << i << ", " << keys[i] << ", " << values[i].getNombre() << ", " << values[i].getApellidoP() << ", " << values[i].getApellidoM() << ", " << values[i].getDinero() << "]\n";
	}
	return aux.str();
}

#endif /* HASH_H_ */
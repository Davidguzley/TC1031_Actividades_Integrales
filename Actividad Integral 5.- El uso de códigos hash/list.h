/*
 * list.h
 *  Created on: 27/09/2020
 *      Author: David Guzman Leyva
 *  Description: Archivo con clases para generar listas ligadas
 *  simples.
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T> class List;

//Clase para cada elemento de la lista
template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

//Clase para crear listas ligadas simples
template <class T>
class List {
public:
	List();
  void clear();
	~List();

  bool empty() const;
  string toString() const;

  void addFirst(T);
	void add(T);//Añade valores a la lista

	T remove(int);//Borra valores de la lista
  T removeFirst ();

  int find(string) const;//Busca la pocision de un elemento de la lista y devuelve -1 si no se encuentra

private:
	Link<T> *head;
	int 	size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

//Limpia la lista
template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
List<T>::~List() {
	clear();
}

//Guarda en un string la lista
template <class T>
string List<T>::toString() const {
	stringstream aux;
	Link<T> *p;
	p = head;
	while (p != 0) {
		aux << p->value.getCuentaNum();
		if (p->next != 0) {
			aux << ",";
		}
		p = p->next;
	}
	return aux.str();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

//Añade el primer valor a la lista
template <class T>
void List<T>::addFirst(T val) {
	Link<T> *newLink;

	newLink = new Link<T>(val);

	newLink->next = head;
	head = newLink;
	size++;
}

//Añade valores a la lista
template <class T>
void List<T>::add(T val) {
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);

	if (empty()) {
    addFirst(val);
    return;
	}

	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
T List<T>::removeFirst() {
	T val;
	Link<T> *p;

	if (empty()) {
		cout<< "No existen elementos en la lista" << endl;
	}

	p = head;

	head = p->next;
	val = p->value;

	delete p;
	size--;

	return val;
}

template <class T>
T List<T>::remove(int index) {
  T val;
	Link<T> *p, *q;
	int pos;

	if (index < 0 || index >= size) {
		cout<< "Indice invalido" << endl;
	}

	if (index == 0) {
    return removeFirst();
	}

  pos = 0;
	p = head;
  q = 0;
	while (pos != index) {
    q = p;
		p = p->next;
		pos++;
	}

  val= p->value;
  q->next = p->next;

  delete p;
  return val;
  size--;
}

template <class T>
int List<T>::find(string val) const {
  int pos;
	Link<T> *p;

	p = head;
  pos = 0;
	while (p != 0) {
		if (p->value.getCuentaNum() == val) {
			return pos;
		}
		p = p->next;
    pos++;
	}
  return -1;
}

#endif
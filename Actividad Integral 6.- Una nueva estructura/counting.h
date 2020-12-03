/*
 * counting.h
 *
 *  Created on: 30/11/2020
 *      Author: David Guzman Leyva
 *  Description: File to create counting sorts
 */

#ifndef COUNTING_H_
#define COUNTING_H_

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std; 
  
template <class T>
class Counting {
private:
  vector<T> v;
  T output[10000];
  T count[10000];
  T aux[10000];
public:
	Counting(vector<T>&);//constructor
  void countSort();//ordena
  string toStringArray() ;//save counts
  string toStringCount();//save
};

template <class T>
Counting<T>::Counting(vector<T> &_v) { //constructor
  v= _v;
}

template <class T>
//Constructor
void Counting<T>::countSort() {
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int max = v[0];

  // Find the largest element of the array
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > max)
      max = v[i];
  }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < v.size(); i++) {
    count[v[i]]++;
    aux[v[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = v.size() - 1; i >= 0; i--) {
    output[count[v[i]] - 1] = v[i];
    count[v[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < v.size(); i++) {
    v[i] = output[i];
  }
}

template <class T>
// Function to print counts
string Counting<T>::toStringCount() {
  stringstream s;
  int flag1 = 0;
  int flag2 = 0;
  int flag3 = 0;
  int flag4 = 0;
  int p = 0;

  while(flag1 == 0 || flag2 == 0 || flag3 == 0 || flag4 == 0) {
    if(v[p] == 1 && flag1 == 0) { //Show count of candidate 1
      s << "El candidato "<< v[p] << " Benji tuvo " << aux[v[p]] << " votos" << endl;
      flag1 = 1;
      p++;
    }
    else if(v[p] == 2 && flag2 == 0) { //Show count of candidate 2
      s << "El candidato "<< v[p] << " Pedro tuvo " << aux[v[p]] << " votos" << endl;
      flag2 = 1;
      p++;
    }
    else if(v[p] == 3 && flag3 == 0) { //Show count of candidate 3
      s << "El candidato "<< v[p] << " Eloína tuvo " << aux[v[p]] << " votos" << endl;
      flag3 = 1;
      p++;
    }
    else if(v[p] == 4 && flag4 == 0) { //Show count of candidate 3
      s << "El candidato "<< v[p] << " Fabiola tuvo " << aux[v[p]] << " votos" << endl;
      flag4 = 1;
      p++;
    }
    else {
      p++;
    }
  }
  return s.str();
}

//Function to print an Array
template <class T>
string Counting<T>::toStringArray() {
	stringstream s;
	s << "[";
  for (int i = 0; i < v.size(); i++) {
		if (i != 0) {
			s << " ";
		} s << v[i];
	} s << "]";
	return s.str();
}


#endif
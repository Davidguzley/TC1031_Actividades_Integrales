/* casosPrueba.h
 *
 *  Created on: 21/09/2020
 *      Author: David Guzman Leyva
 * Description: sirve para correr funciones de casos de prueba
 */

#ifndef CASOSPRUEBA_H_
#define CASOSPRUEBA_H_

#include <cstring>
#include "counting.h"

using namespace std;


void casosPrueba() {
  string ans;

  //CASO 1
  vector<int> v1;
  v1.push_back(1);
  v1.push_back(4);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(1);
  v1.push_back(3);
  Counting<int> resultado1(v1);
  resultado1.countSort();
  ans= "[1 1 2 3 3 4]";

	cout << " CASO 1: " <<	( (!ans.compare(resultado1.toStringArray().c_str())) ? "success\n" : "fail\n");

  //CASO 2
  vector<int> v2;
  v2.push_back(1);
  v2.push_back(1);
  v2.push_back(1);
  v2.push_back(1);
  v2.push_back(1);
  v2.push_back(1);
  Counting<int> resultado2(v2);
  resultado2.countSort();
  ans= "[1 1 1 1 1 1]";

	cout << " CASO 2: " <<	( (!ans.compare(resultado2.toStringArray().c_str())) ? "success\n" : "fail\n");

  //CASO 3
  vector<int> v3;
  v3.push_back(5);
  v3.push_back(3);
  v3.push_back(10);
  v3.push_back(6);
  v3.push_back(12);
  v3.push_back(4);
  Counting<int> resultado3(v3);
  resultado3.countSort();
  ans= "[3 4 5 6 10 12]";

	cout << " CASO 3: " <<	( (!ans.compare(resultado3.toStringArray().c_str())) ? "success\n" : "fail\n");


}

#endif
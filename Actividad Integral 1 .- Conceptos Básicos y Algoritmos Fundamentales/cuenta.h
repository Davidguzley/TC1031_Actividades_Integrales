/*
 * cuenta.h
 *
 *  Created on: 21/09/2020
 *      Author: David Guzman Leyva
 */

#ifndef CUENTA_H
#define CUENTA_H

#include<iostream>
using namespace std;

class Cuenta{
  private:
    string cuentaNum, nombre, apellidoP, apellidoM;
    int dinero;

  public:
    Cuenta(string num, string n, string ap, string am, int d){
      cuentaNum = num;
      nombre = n;
      apellidoP = ap;
      apellidoM = am;
      dinero = d;
    }

    void mostrar(){
      cout << "\n" << cuentaNum << " " << nombre << " " << apellidoP << " " << apellidoM << " " << dinero << endl;
    }

    string getCuentaNum(){
      return cuentaNum;
    }

    string getNombre(){
      return nombre;
    }

    string getApellidoP(){
      return apellidoP;
    }

    string getApellidoM(){
      return apellidoM;
    }

    int getDinero(){
      return dinero;
    }
};
 #endif

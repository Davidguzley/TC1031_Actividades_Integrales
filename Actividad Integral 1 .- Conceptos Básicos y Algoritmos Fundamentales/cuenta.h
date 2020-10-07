 /*
 * cuenta.h
 *
 *  Created on: 21/09/2020
 *      Author: David Guzman Leyva
 *
 * Description: Clase para almacenar los atributos de cada cuenta
 * como dentro de un objeto
 */


#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
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
    
    //Muestra los atributos en consola
    void mostrar(){
      cout << cuentaNum << " " << nombre << " " << apellidoP << " " << apellidoM << " " << dinero << endl;
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

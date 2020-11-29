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

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Cuenta{
  private:
    string cuentaNum, nombre, apellidoP, apellidoM;
    int dinero;

  public:
    Cuenta (){};
    Cuenta(string num, string n, string ap, string am, int d){
      cuentaNum = num;
      nombre = n;
      apellidoP = ap;
      apellidoM = am;
      dinero = d;
    }
    
    //Muestra los atributos en un string
    string mostrar() const {
      stringstream aux;
      aux << cuentaNum << " " << nombre << " " << apellidoP << " " << apellidoM << " " << dinero;
      return aux.str();
    }

    void actualizarDatos(){
      string n, ap, am;

      cout << "Escribe el nuevo nombre de la cuenta que deseas actualizar." << endl;
      cin >> n;
      nombre = n;

      cout << "Escribe el nuevo apellido paterno de la cuenta que deseas actualizar." << endl;
      cin >> ap;
      apellidoP = ap;

      cout << "Escribe el nuevo apellido materno de la cuenta que deseas actualizar." << endl;
      cin >> am;
      apellidoM = am;
    }

    //Devuelve el numero de cuenta del cliente
    string getCuentaNum(){
      return cuentaNum;
    }

    //Devuelve el nombre del cliente
    string getNombre(){
      return nombre;
    }

    //Devuelve el apellido paterno del cliente
    string getApellidoP(){
      return apellidoP;
    }

    //Devuelve el apellido materno del cliente
    string getApellidoM(){
      return apellidoM;
    }

    //Devuelve la cantidad de dinero del cliente
    int getDinero(){
      return dinero;
    }
};
 #endif
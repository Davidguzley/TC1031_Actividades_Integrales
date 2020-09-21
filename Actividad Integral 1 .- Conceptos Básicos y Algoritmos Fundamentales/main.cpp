/*
 * main.cpp
 *
 *  Created on: 21/09/2020
 *      Author: David Guzman Leyva
 */

#include <fstream>
#include "sorts.h"
#include "cuenta.h"

using namespace std;

int main() {
  //Para archivos
  ifstream inputFile;
	ofstream outputFile;

  //Vector
	vector<Cuenta> v;

  //Variables del txt
  string nombre, apellidoP, apellidoM, cuentaNum;
  int dinero;

  inputFile.open("cuentas.txt");
  //Almacenar en vector
	if (inputFile.is_open()) {
		while (inputFile>>cuentaNum>>nombre>>apellidoP>>apellidoM>>dinero){
      //cout<<cuentaNum<<endl;
      //cout<<nombre<<endl;
      //cout<<apellidoP<<endl;
      //cout<<apellidoM<<endl;
      //cout<<dinero<<endl;
      Cuenta cuentaUsuario(cuentaNum,nombre,apellidoP,apellidoM,dinero);
      v.push_back(cuentaUsuario);
		}

    //Ordenamos y mostramos
    ordenaBurbuja(v);
    //cout<< v.size()<<endl;
    for(int i = 0; i < v.size(); i++){
        v[i].mostrar();
    }

    //Almacenar ordenados en txt
    outputFile.open("ordenados.txt");
    if (outputFile.is_open()) {
      for (int i = 0; i < v.size(); i++) {
          outputFile << v[i].getCuentaNum() << " " << v[i].getNombre() << " " << v[i].getApellidoP() << " " << v[i].getApellidoM() << " " << v[i].getDinero()<<endl;
      }
    }

    //BUSQUEDA DEL USUARIO
    int r_inicio, r_final, inicio, final;

    cout << "\n" << "Define un rango de cantidad de dinero en cuentas para buscar" << endl;
    cout << "Rango inicial: " << endl;
    cin >> r_inicio;
    //inicio = busqBinaria(v, 0);
    //inicio = busqBinaria(v, 708);
    //inicio = busqBinaria(v, 10);
    inicio = busqBinaria(v, r_inicio);

    cout << "Rango Final: " << endl;
    cin >> r_final;
    //final= busqBinaria(v, 11);
    //final= busqBinaria(v, 708);
    //final= busqBinaria(v, 100000);
    final = busqBinaria(v, r_final);

    for (int i = inicio; i <= final; i++) {
        v[i].mostrar();
    }
	}

  else{
    cout<<"Fallo al abrir archivo"<<endl;
    return 0;
  }

  inputFile.close();
	return 0;
}

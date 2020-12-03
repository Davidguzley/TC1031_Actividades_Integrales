/*
 * main.cpp
 *
 *  Created on: 29/11/2020
 *      Author: David Guzman Leyva
 */

#include <iostream>
#include <fstream>
#include "counting.h"
#include "casosPrueba.h"

using namespace std;

int main(){
  //ACTVIDAD EXTRA
  cout << "\n" << "**********************************************************" << endl;

  //Para archivos
  ifstream inputFile;
	ofstream outputFile;

  //Para hacer pregunta
  string pregunta;

  //Vector
	vector<int> votos;
  
  //Variables de los txt
  string nombre, apellidoP, apellidoM;
  int voto;
  
  //Abrimos el archivo
  cout << "Leyendo archivo votaciones.txt y guardando vector con votaciones............" << endl;
  inputFile.open("votaciones.txt");
	if (inputFile.is_open()) {
		while (inputFile>>nombre>>apellidoP>>apellidoM>>voto){
      //mostrar lo contenido en el archivo
      cout << nombre << " " << apellidoP << " " << apellidoM << " " << voto << endl;

      //Almacenando en vector
      votos.push_back(voto);
		}
    cout << "Archivo leido exitosamente........................." << endl;
    inputFile.close();


    //VOTACION DEL USUARIO
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Escribe por quien votarias como mejor profesor" << endl;
    cout << "1: " << "Benji" << endl;
    cout << "2: " << "Pedro" << endl;
    cout << "3: " << "Eloína" << endl;
    cout << "4: " << "Fabiola" << endl;
    int newVote;
    cin >> newVote;
    cout << "GRACIAS POR TU VOTO, AUNQUE TODOS SABEMOS QUE EL MEJOR ES BENJI!!!!!!" << endl;
    votos.push_back(newVote);
    // Creando Counting y ordenado los votos
    Counting<int> resultados(votos);
    resultados.countSort();

    //Mostramos Resultados
    cout << "\n" << "**********************************************************" << endl;
    cout << "LOS RESULTADOS SON:" << endl;
    resultados.toStringCount();
    cout << resultados.toStringCount() << endl;
    cout << "ARREGLO DE VOTOS ORDENADO:" << endl;
    cout << resultados.toStringArray() << endl;

    //Almacenar resultados de votaciones en txt
    cout << '\n' << "Almacenando resultados y ordenamiento de votaciones........................." << endl;
    outputFile.open("resultado.txt");
    if (outputFile.is_open()) {
      outputFile << "LOS RESULTADOS SON:" << endl;
      outputFile << resultados.toStringCount() << endl;
      outputFile << "ARREGLO DE VOTOS ORDENADO:" << endl;
      outputFile << resultados.toStringArray() << endl;
    }
    outputFile.close();
    cout << "Almacenamiento exitoso........................." << endl;


    //CASOS DE PRUEBA
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres correr unos casos de prueba? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
      casosPrueba();
    }
    else{
      cout<<"Ok sera para la proxima"<<endl;
    }

	}

  else{
    cout<< "\n" << "Fallo al abrir archivo"<<endl;
    return 0;
  }

}
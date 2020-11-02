/*
 * main.cpp
 *
 *  Created on: 21/09/2020
 *      Author: David Guzman Leyva
 */

#include <fstream>
#include "sorts.h"
#include "cuenta.h"
#include "casosPrueba.h"
#include "list.h"
#include "heap.h"

using namespace std;

int main() {
  //ACTVIDAD 1
  cout << "\n" << "**********************************************************" << endl;

  //Para archivos
  ifstream inputFile;
	ofstream outputFile;

  //Para hacer pregunta
  string pregunta;

  //Vector
	vector<Cuenta> v;

  //Lista ligada simple
  List<Cuenta> lista;

  //Arbol Heap
  Heap<string> arbol(20);
  
  //Variables de los txt
  string nombre, apellidoP, apellidoM, cuentaNum, line;
  int dinero;
  
  //Abrimos el archivo
  cout << "Leyendo archivo cuentas.txt y guardando vector con cuentas de clientes............" << endl;
  inputFile.open("cuentas.txt");
	if (inputFile.is_open()) {
		while (inputFile>>cuentaNum>>nombre>>apellidoP>>apellidoM>>dinero){
      //mostrar lo contenido en el archivo
      cout<< cuentaNum << " " << nombre << " " << apellidoP << " " << apellidoM << " " << dinero << " " << endl;

      //Almacenando en vector
      Cuenta cuentaUsuario(cuentaNum,nombre,apellidoP,apellidoM,dinero);
      v.push_back(cuentaUsuario);
		}

    cout << "Archivo leido exitosamente........................." << endl;
    inputFile.close();

    //Ordenamos y mostramos
    cout << '\n' << "Ordenando vector........................." << endl;
    ordenaBurbuja(v);
    //cout<< v.size()<<endl respuesta 10;
    for(int i = 0; i < v.size(); i++){
        v[i].mostrar();
    }
    cout << "vector ordenado........................." << endl;

    //Almacenar ordenados en txt
    cout << '\n' << "Almacenando ordenamiento........................." << endl;
    outputFile.open("ordenados.txt");
    if (outputFile.is_open()) {
      for (int i = 0; i < v.size(); i++) {
          outputFile << v[i].getCuentaNum() << " " << v[i].getNombre() << " " << v[i].getApellidoP() << " " << v[i].getApellidoM() << " " << v[i].getDinero()<<endl;
      }
    }
    outputFile.close();
    cout << "Almacenamiento exitoso........................." << endl;


    //BUSQUEDA DEL USUARIO
    cout << "\n" << "**********************************************************" << endl;
    int r_inicio, r_final, inicio, final;
    cout << "\n" << "Define un rango de cantidad de dinero en cuentas para buscar" << endl;
    cout << "Rango inicial: " << endl;
    cin >> r_inicio;
    inicio = busqBinaria(v, r_inicio);
    cout << "Rango Final: " << endl;
    cin >> r_final;
    final = busqBinaria(v, r_final);

    //Mostramos resultado de la busqueda
    cout << "\n" << "Resultado de la busqueda: " << endl;
    for (int i = inicio; i <= final; i++) {
        v[i].mostrar();
    }
    

    //CASOS DE PRUEBA
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres correr unos casos de prueba? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
      casosRango(v);
    }
    else{
      cout<<"Ok sera para la proxima"<<endl;
    }

	}

  else{
    cout<< "\n" << "Fallo al abrir archivo"<<endl;
    return 0;
  }



  //ACTIVIDAD 2
  cout << "\n" << "**********************************************************" << endl;
  //Abrimos el archivo
  cout << "\n" << "Leyendo archivo ordenados.txt y guardando en lista numero de cuentas de clientes............" << endl;
  inputFile.open("ordenados.txt");
	if (inputFile.is_open()) {
		while (inputFile>>cuentaNum>>nombre>>apellidoP>>apellidoM>>dinero){
      //mostrar lo contenido en el archivo
      cout<< cuentaNum << " " << nombre << " " << apellidoP << " " << apellidoM << " " << dinero << " " << endl;

      //Almacenando en lista
      Cuenta cuentaUsuario(cuentaNum,nombre,apellidoP,apellidoM,dinero);
      lista.add(cuentaUsuario);
		}

    cout << "Archivo leido exitosamente........................." << endl;
    inputFile.close();
    
    //Mostramos la lista
    cout << "\n" << "Lista ligada simple creada............" << endl;
    cout << lista.toString() <<endl;

    //Almacenar lista con numeros de cuenta en txt
    cout << '\n' << "Almacenando lista con numeros de cuenta en txt........................." << endl;
    outputFile.open("cuentasLista.txt");
    if (outputFile.is_open()) {
      outputFile << lista.toString() <<endl;
    }
    outputFile.close();
    cout << "Almacenamiento exitoso........................." << endl;
    
	}

  else{
    cout<<"Fallo al abrir archivo"<<endl;
    return 0;
  }



  //ACTIVIDAD 3
  cout << "\n" << "**********************************************************" << endl;
  //Abrimos el archivo
  cout << "\n" << "Leyendo archivo cuentasLista.txt y guardando cuentas de clientes en arbol heap............" << endl;
  inputFile.open("cuentasLista.txt");
	if (inputFile.is_open()) {
    while(getline(inputFile,line)) {
        stringstream stream(line);
        //Mostrar cada valor contenido en el archivo
        cout << "Contenido del archivo cuentasLista.txt:\n";
        while(getline(stream,cuentaNum,',')) {
          cout << "valor leido: " << cuentaNum << '\n';
          //Almacenando en arbol heap
          arbol.push(cuentaNum);
        }
    }

    cout << "Archivo leido exitosamente........................." << endl;
    inputFile.close();
    
    //Mostramos el contenido del arbol
    cout << "\n" << "Arbol Heap creado............" << endl;
    cout << arbol.toString() <<endl;

    //Almacenar ordenados en txt
    cout << '\n' << "Almacenando arbol con numeros de cuenta en txt........................." << endl;
    outputFile.open("cuentasArbol.txt");
    if (outputFile.is_open()) {
      outputFile << arbol.toString() <<endl;
    }
    outputFile.close();
    cout << "Almacenamiento exitoso........................." << endl;
    

    //BUSQUEDA DE NUMERO DE CUENTA
    cout << "\n" << "**********************************************************" << endl;
    string busqCuenta;
    cout << "\n" << "Escribe el numero de cuenta que deseas buscar" << endl;
    cin >> busqCuenta;
    //Se realiza la busqueda
    if(arbol.busqSecuencial(busqCuenta)){
      cout << "Numero de cuenta encontrado" << endl;
    }
    else{
      cout << "El numero de cuenta no existe" << endl;
    }


    //CASOS DE PRUEBA
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres correr unos casos de prueba? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
      casosBusqSecuencial(arbol);
    }
    else{
      cout<<"Ok sera para la proxima"<<endl;
    }

	}

  else{
    cout<<"Fallo al abrir archivo"<<endl;
    return 0;
  }

	return 0;
}
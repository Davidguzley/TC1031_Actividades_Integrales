/*
 * main.cpp
 *
 *  Created on: 29/11/2020
 *      Author: David Guzman Leyva
 */

#include <fstream>
#include "sorts.h"
#include "cuenta.h"
#include "casosPrueba.h"
#include "list.h"
#include "heap.h"
#include "hash.h"

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main() {
  //ACTVIDAD 1 (ADD)
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

  //Tabla hash
  HashTable<string, Cuenta> hash(10, string ("empty"), myHash);
  
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
        cout << v[i].mostrar() << endl;
    }
    cout << "vector ordenado........................." << endl;

    //Almacenar ordenados en txt
    cout << '\n' << "Almacenando ordenamiento........................." << endl;
    outputFile.open("ordenados.txt");
    if (outputFile.is_open()) {
      for (int i = 0; i < v.size(); i++) {
          outputFile << v[i].mostrar()<< endl;
      }
    }
    outputFile.close();
    cout << "Almacenamiento exitoso........................." << endl;


    //BUSQUEDA DEL USUARIO
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres saber que cuentas poseen un determinado rango de dinero? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
      int r_inicio, r_final;
      cout << "\n" << "Define el rango de cantidad de dinero en cuentas para buscar" << endl;
      cout << "Rango inicial: " << endl;
      cin >> r_inicio;
      cout << "Rango Final: " << endl;
      cin >> r_final;
      //Se realiza la busqueda por rango
      pruebaRango(v, r_inicio, r_final);
    }
    else{
      cout<<"Ok sera para la proxima"<<endl;
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



  //ACTIVIDAD 2 (REMOVE)
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


    //REMOVER UNA CUENTA DEL SISTEMA
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres eliminar una cuenta de un cliente? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
      string deleteCuenta;
      cout << "\n" << "Escribe el numero de cuenta que deseas borrar del sistema: " << endl;
      cin >> deleteCuenta;
      //Se realiza la eliminacion
      pruebaDelete(lista, deleteCuenta);
    }
    else{
      cout<<"Ok sera para la proxima"<<endl;
    }
    

    //Almacenar lista con numeros de cuenta en txt
    cout << '\n' << "Almacenando lista con numeros de cuenta en txt........................." << endl;
    outputFile.open("cuentasLista.txt");
    if (outputFile.is_open()) {
      outputFile << lista.toString() <<endl;
    }
    outputFile.close();
    cout << "Almacenamiento exitoso........................." << endl;


    //CASOS DE PRUEBA
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres correr unos casos de prueba? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
      casosDelete(lista);
    }
    else{
      cout<<"Ok sera para la proxima"<<endl;
    }
	}

  else{
    cout<<"Fallo al abrir archivo"<<endl;
    return 0;
  }



  //ACTIVIDAD 3 (FIND)
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
    cout << "\n" << "Tamaño del arbol: " << arbol.size() << endl;

    //Almacenar arbol en txt
    cout << '\n' << "Almacenando arbol con numeros de cuenta en txt........................." << endl;
    outputFile.open("cuentasArbol.txt");
    if (outputFile.is_open()) {
      outputFile << arbol.toString() <<endl;
    }
    outputFile.close();
    cout << "Almacenamiento exitoso........................." << endl;
    

    //BUSQUEDA DE NUMERO DE CUENTA
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres buscar el numero de cuenta de un cliente? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
    string busqCuenta;
    cout << "\n" << "Escribe el numero de cuenta que deseas buscar" << endl;
    cin >> busqCuenta;
    //Se realiza la busqueda
    pruebaBusqSecuencial(arbol, busqCuenta);
    }
    else{
      cout<<"Ok sera para la proxima"<<endl;
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



  //ACTIVIDAD 4 (UPDATE)
  cout << "\n" << "**********************************************************" << endl;
  //Abrimos el archivo
  cout << "\n" << "Leyendo archivo cuentasArbol.txt y guardando datos de cuentas de clientes en tabla hash............" << endl;
  inputFile.open("cuentasArbol.txt");
	if (inputFile.is_open()) {
    while(getline(inputFile,line)) {
        stringstream stream(line);
        //Mostrar cada valor contenido en el archivo
        cout << "Contenido del archivo cuentasLista.txt:\n";
        while(getline(stream,cuentaNum,',')) {
          cout << "valor leido: " << cuentaNum << '\n';
          //Almacenando en arbol heap
          for(int i = 0; i < v.size(); i++){
            if(v[i].getCuentaNum() == cuentaNum){
              hash.put(cuentaNum, v[i]);
            }
          }
        }
    }
    
    cout << "Archivo leido exitosamente........................." << endl;
    inputFile.close();
    
    //Mostramos el contenido de la tabla hash
    cout << "\n" << "Tabla hash creada............" << endl;
    cout << hash.toString() <<endl;
    
    
    //ACTUALIZAR DATOS DE UN NUMERO DE CUENTA
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres actualizar los datos de un cliente? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
      string llave;
      cout << "\n" << "Escribe el numero de cuenta que deseas actualizar" << endl;
      cin >> llave;

      pruebaSetCuenta(hash, llave);

    }
    else{
      cout<<"Ok sera para la proxima"<<endl;
    }

    //Almacenar tabla en txt
    cout << '\n' << "Almacenando tabla hash con cuentas de clientes en txt........................." << endl;
    outputFile.open("cuentasHash.txt");
    if (outputFile.is_open()) {
      outputFile << hash.toString() <<endl;
    }
    outputFile.close();
    cout << "Almacenamiento exitoso........................." << endl;

    
    //CASOS DE PRUEBA
    cout << "\n" << "**********************************************************" << endl;
    cout << "\n" << "Quieres correr unos casos de prueba? si/no" << endl;
    cin>>pregunta;
    if (pregunta=="si"){
      casoSetCuenta(hash);
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
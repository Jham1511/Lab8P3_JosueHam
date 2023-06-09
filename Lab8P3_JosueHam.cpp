#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "Cohete.h"
#include "Marte.h"
#include "Neptuno.h"
using namespace std;
int randomNeptuno() {
	int aleatorio = 1 + rand() % (4 - 1);
	return aleatorio;
}
int menu() {
	cout << "\nMenu del Programa" << endl
		<< "1 -> Leer Archivo" << endl
		<< "2 -> Guardar Bitacora" << endl
		<< "3 -> Eliminar Bitacora" << endl
		<< "4 -> Salir" << endl
		<< "Ingrese la opcion que desea: " << endl;
	int numero;
	cin >> numero;
	return numero;
}
int main()
{
	int opcionIngresada = menu();
	vector<Cohete> cohetesCreados;
	bool leyoArchivo = false;
	while (opcionIngresada!=4)
	{
		switch (opcionIngresada) {
		case 1: {
			leyoArchivo = true;
			ifstream archivoCohetes("spaceZ.txt" , ios::in);
			
			string texto; 
			if (archivoCohetes.fail())
			{
				cout << "El archivo no se pudo abrir" << endl;
			}
			while (!archivoCohetes.eof())
			{	
				string nombre, strAlaIzquierda, strAlaDerecha, strTanqueGasolina, NombrePlaneta;

				while (getline(archivoCohetes, texto))
				{
					stringstream stream(texto);
					getline(stream, nombre, ';');
					getline(stream, strAlaIzquierda, ';');
					getline(stream, strAlaDerecha, ';');
					getline(stream, strTanqueGasolina, ';');
					getline(stream, NombrePlaneta, ';');
					Cohete coheteTemporal;
					int alaIzquierda = stoi(strAlaIzquierda), alaDerecha = stoi(strAlaDerecha), tanqueGasolina;
					coheteTemporal.setAlaIzquierda(alaIzquierda);
					coheteTemporal.setAlaDerecha(alaDerecha);
					coheteTemporal.setTanque(tanqueGasolina);
					if (NombrePlaneta == "Marte")
					{
						Marte mart(400000);
					} else if (NombrePlaneta == "Neptuno") {
						
						//Neptuno nept(700000);
					}
					else if (NombrePlaneta == "Saturno") {

					}
				}
			} 

			archivoCohetes.close();
			break;
		}//Leer archivo
		case 2: {
			if (leyoArchivo)
			{

			}
			else {
				cout << "No se ha leido el archivo" << endl;
			}
		}//Guardar archivo
		case 3: {
			if (leyoArchivo)
			{

			}
			else {
				cout << "No se ha leido el archivo" << endl;
			}
		}//Eliminar bitacora
		default:
			cout << "..." << endl;
		}//Fin del switch
		opcionIngresada = menu();
	}//Fin del while
}

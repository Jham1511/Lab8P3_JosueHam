#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "Cohete.h"
#include "Marte.h"
#include "Neptuno.h"
#include "Saturno.h"
using namespace std;

int randomAsteroides() {
	int aleatorio = 1 + rand() % (101 - 1);
	return aleatorio;
}
void imprimirCohetes(vector<Cohete> cohetes) {
	for (int i = 0; i < cohetes.size(); i++)
	{
		cout << "Posicion: " << i << endl
			<< "Nombre: " << cohetes[i].getNombre() << endl
			<< "Destino: " << cohetes[i].getDestino() << endl;
	}
}
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
	srand(time(NULL));
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
			Cohete coheteTemporal;
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
					getline(stream, nombre, ',');
					getline(stream, strAlaIzquierda, ',');
					getline(stream, strAlaDerecha, ',');
					getline(stream, strTanqueGasolina, ',');
					getline(stream, NombrePlaneta, ',');
					coheteTemporal.setNombreBautizo(nombre);
					coheteTemporal.setDestino(NombrePlaneta);
					coheteTemporal.setAlaIzquierda(stoi(strAlaIzquierda));
					coheteTemporal.setAlaDerecha(stoi(strAlaDerecha));
					coheteTemporal.setTanque(stoi(strTanqueGasolina));
					cohetesCreados.push_back(coheteTemporal);
				}
				imprimirCohetes(cohetesCreados);
			} 
			cout << "Archivo leido y cohetes cargados correctamente" << endl;
			archivoCohetes.close();
			break;
		}//Leer archivo
		case 2: {
			if (leyoArchivo)
			{
				ofstream bitacora("bitacora.txt", ios::out);
				if (bitacora.fail()) cout << "No se pudo abrir el archivo" << endl;

				for (Cohete cuete : cohetesCreados)
				{
					string destino = cuete.getDestino();
					int probabilidadAsteroides = randomAsteroides();
					if (destino == "Marte")
					{
						Marte planetaMarte;
						if (probabilidadAsteroides <= 20)
						{	
							if (cuete.getTanque() <= planetaMarte.getMinimoGasolina())
							{
								bitacora << "El cohete " << cuete.getNombre() << " se quedo sin gasolina y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else {
								bitacora << "El cohete " << cuete.getNombre() << " llego con exito a " << cuete.getDestino() << endl;
							}
						}
						else {
							int danioMeteoritos = 40;
							int resAlaIzquierda = cuete.getAlaIzquierda(), resAlaDerecha = cuete.getAlaDerecha();
							cuete.setAlaDerecha(resAlaDerecha - danioMeteoritos);
							cuete.setAlaIzquierda(resAlaIzquierda - danioMeteoritos);
							if (cuete.getTanque() <= planetaMarte.getMinimoGasolina())
							{
								bitacora << "El cohete " << cuete.getNombre() << " se quedo sin gasolina y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else if(cuete.getAlaDerecha() == 0 || cuete.getAlaIzquierda() == 0){
								bitacora << "El cohete " << cuete.getNombre() + " perdio ambas alas y no pudo llegar a "
									<< cuete.getDestino() << endl;
							}
							else if (cuete.getAlaDerecha() == 0) {
								bitacora << "El cohete " << cuete.getNombre() << " perdio el ala derecha y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else if (cuete.getAlaIzquierda() == 0) {
								bitacora << "El cohete " << cuete.getNombre() << " perdio el ala izquierda y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else {
								bitacora << "El cohete " << cuete.getNombre() << " llego con exito a " << cuete.getDestino() << endl;
							}
						}
					}//Fin marte

					else if (destino == "Neptuno") {
						Neptuno planetaNeptuno;
						int rutaAceptada = randomNeptuno();
						if (probabilidadAsteroides > 90)
						{
							if (cuete.getTanque() <= planetaNeptuno.getMinimoGasolina())
							{
								bitacora << "El cohete " << cuete.getNombre() << " se quedo sin gasolina y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else if(rutaAceptada == 2 && cuete.getTanque() >= planetaNeptuno.getMinimoGasolina()) {
								bitacora << "El cohete " <<  cuete.getNombre() <<  " de manera milagrosa logró llegar a Neptuno";
							}
							else {
								bitacora << "El cohete " << cuete.getNombre() << " se perdio en el silencioso espacio tratando de llegar a Neptuno" << endl;
						}
						}
						else if (probabilidadAsteroides <= 90) {
							int danioMeteoritos = 40;
							int resAlaIzquierda = cuete.getAlaIzquierda(), resAlaDerecha = cuete.getAlaDerecha();
							cuete.setAlaDerecha(resAlaDerecha - danioMeteoritos);
							cuete.setAlaIzquierda(resAlaIzquierda - danioMeteoritos);
							if (cuete.getTanque() <= planetaNeptuno.getMinimoGasolina())
							{
								bitacora << "El cohete " << cuete.getNombre() << " se quedo sin gasolina y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else if (rutaAceptada == 2 && cuete.getTanque() >= planetaNeptuno.getMinimoGasolina()) {
								bitacora << "El cohete " << cuete.getNombre() << " de manera milagrosa logró llegar a Neptuno";
							}
							else if (cuete.getAlaDerecha() == 0 || cuete.getAlaIzquierda() == 0) {
								bitacora << "El cohete " << cuete.getNombre() + " perdio ambas alas y no pudo llegar a "
									<< cuete.getDestino() << endl;
							}
							else if (cuete.getAlaDerecha() == 0) {
								bitacora << "El cohete " << cuete.getNombre() << " perdio el ala derecha y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else if (cuete.getAlaIzquierda() == 0) {
								bitacora << "El cohete " << cuete.getNombre() << " perdio el ala izquierda y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else {
								bitacora << "El cohete " << cuete.getNombre() << " se perdio en el silencioso espacio tratando de llegar a Neptuno" << endl;
							} 
						}
						else if (destino == "Saturno") {
						Saturno planetaSaturno;
						if (probabilidadAsteroides <= 50)
						{
							if (cuete.getTanque() <= planetaSaturno.getMinimoGasolina())
							{
								bitacora << "El cohete " << cuete.getNombre() << " se quedo sin gasolina y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else {
								bitacora << "El cohete " << cuete.getNombre() << " llego con exito a " << cuete.getDestino() << endl;
							}
						}
						else {
							int danioMeteoritos = 40;
							int resAlaIzquierda = cuete.getAlaIzquierda(), resAlaDerecha = cuete.getAlaDerecha();
							int danioSaturno = planetaSaturno.getDanio();
							cuete.setAlaDerecha(resAlaDerecha - danioMeteoritos - danioSaturno);
							cuete.setAlaIzquierda(resAlaIzquierda - danioMeteoritos - danioSaturno);
							if (cuete.getTanque() <= planetaSaturno.getMinimoGasolina())
							{
								bitacora << "El cohete " << cuete.getNombre() << " se quedo sin gasolina y no pudo llegar a" << cuete.getDestino() << endl;
							}
							else if (cuete.getAlaDerecha() == 0 || cuete.getAlaIzquierda() == 0) {
								bitacora << "El cohete " << cuete.getNombre() + " perdio ambas alas y no pudo llegar a "
									<< cuete.getDestino() << endl;
							}
							else if (cuete.getAlaDerecha() == 0) {
								bitacora << "El cohete " << cuete.getNombre() << " perdio el ala derecha y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else if (cuete.getAlaIzquierda() == 0) {
								bitacora << "El cohete " << cuete.getNombre() << " perdio el ala izquierda y no pudo llegar a " << cuete.getDestino() << endl;
							}
							else {
								bitacora << "El cohete " << cuete.getNombre() << " llego con exito a " << cuete.getDestino() << endl;
							}
						}
					}//Fin saturno
				}
			}
				bitacora.close();
			} else { //Se leyo el archivo
				cout << "No se ha leido el archivo" << endl;
			}
			cout << "Bitacora sobre las naves escrita correctamente" << endl;
			break;
		}//Guardar archivo
		case 3: {
			if (leyoArchivo)
			{
				remove("bitacora.txt");
				cout << "Bitacora eliminada correctamente" << endl;
			}
			else {
				cout << "No se ha leido el archivo" << endl;
			}
			break;
		}//Eliminar bitacora
		default:
			cout << "..." << endl;
		}//Fin del switch
		opcionIngresada = menu();
	}//Fin del while
}

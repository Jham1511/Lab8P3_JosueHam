#include <iostream>
using namespace std;
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
	while (opcionIngresada!=4)
	{
		switch (opcionIngresada) {
		case 1: {

			break;
		}//Leer archivo
		case 2: {

		}//Guardar archivo
		case 3: {

		}//Eliminar bitacora
		default:
			cout << "..." << endl;
		}//Fin del switch
		opcionIngresada = menu();
	}//Fin del while
}

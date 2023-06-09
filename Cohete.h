#pragma once
#include <iostream>
#include <string>
using namespace std;
class Cohete
{
private: 
	string nombreBautizo, PlanetaDestino;
	int alaIzquierda, alaDerecha, tanqueGasolina;
public: 
	Cohete();
	Cohete(string, string, int, int, int);
	~Cohete();
	int getAlaIzquierda();
	int getAlaDerecha();
	int getTanque();
	string getNombre();
	string getDestino();
	void setAlaIzquierda(int);
	void setAlaDerecha(int);
	void setTanque(int);
	void setNombreBautizo(string);
	void setDestino(string);
};
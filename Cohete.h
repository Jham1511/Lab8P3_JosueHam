#pragma once
#include <iostream>
#include <string>
using namespace std;
class Cohete
{
private: 
	string nombreBautizo;
	int alaIzquierda, alaDerecha, tanqueGasolina;
public: 
	Cohete();
	Cohete(string, int, int, int);
	~Cohete();
	int getAlaIzquierda();
	int getAlaDerecha();
	int getTanque();
	string getNombre();
	void setAlaIzquierda(int);
	void setAlaDerecha(int);
	void setTanque(int);
	void nombreBautizo(string);
};
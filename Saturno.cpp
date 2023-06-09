#include "Saturno.h"
Saturno::Saturno() {
	danioAlas = 30;
	cantidadGasolina = 700000;
}

Saturno::~Saturno() {

}
int Saturno::getMinimoGasolina() {
	return cantidadGasolina;
}
int Saturno::getDanio() {
	return danioAlas;
}
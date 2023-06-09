#include "Neptuno.h"
Neptuno::Neptuno() {
	cantidadGasolina = 900000;
}


Neptuno::~Neptuno() {

}

int Neptuno::getMinimoGasolina() {
	return cantidadGasolina;
}
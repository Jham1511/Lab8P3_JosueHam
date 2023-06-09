#include "Marte.h"
Marte::Marte() {
	cantidadGasolina = 400000;
}
Marte::~Marte() {

}
int Marte::getMinimoGasolina() {
	return cantidadGasolina;
}
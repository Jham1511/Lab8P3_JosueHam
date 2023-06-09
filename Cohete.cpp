#include "Cohete.h"
Cohete::Cohete() {
	alaIzquierda = 0;
	alaDerecha = 0;
	tanqueGasolina = 0;
	nombreBautizo = "Sin identificar";
}
Cohete::Cohete(string nombre, int alaIzquierda, int alaDerecha, int tanqueGasolina) {
	this->nombreBautizo = nombre;
	this->alaIzquierda = alaIzquierda;
	this->alaDerecha = alaDerecha;
	this->tanqueGasolina = tanqueGasolina;

}

Cohete::~Cohete() {
	
 }
#include "Cohete.h"
Cohete::Cohete() {
	alaIzquierda = 0;
	alaDerecha = 0;
	tanqueGasolina = 0;
	nombreBautizo = "Sin identificar";
}
Cohete::Cohete(string nombre, string destino, int alaIzquierda, int alaDerecha, int tanqueGasolina) {
	this->nombreBautizo = nombre;
	this->PlanetaDestino = destino;
	this->alaIzquierda = alaIzquierda;
	this->alaDerecha = alaDerecha;
	this->tanqueGasolina = tanqueGasolina;

}

Cohete::~Cohete() {
	
 }
int Cohete::getTanque() {
	return tanqueGasolina;
}
int Cohete::getAlaDerecha() {
	return alaDerecha;
}
int Cohete::getAlaIzquierda() {
	return alaIzquierda;
}
string Cohete::getDestino() {
	return PlanetaDestino;
}
void Cohete::setDestino(string destino) {
	PlanetaDestino = destino;
}
void Cohete::setNombreBautizo(string nombre) {
	nombreBautizo = nombre;
}
string Cohete::getNombre() {
	return nombreBautizo;
}
void Cohete::setTanque(int tanque) {
	tanqueGasolina = tanque;
}
void Cohete::setAlaIzquierda(int ala) {
	alaIzquierda = ala;
}
void Cohete::setAlaDerecha(int ala) {
	alaDerecha = ala;
}
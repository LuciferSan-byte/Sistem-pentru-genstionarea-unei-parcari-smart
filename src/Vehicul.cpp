#include "Vehicul.h"

Vehicul::Vehicul(
		int id,
		const std::string & numar,
		const Dimensiune& dim,
		double greutate
		)
{
this->idVehicul = id;
this->numarInmatriculare = numar;
this->dimensiune = dim;
this->greutate = greutate;
}

Dimensiune Vehicul::obtineDimensiune() const {
    return dimensiune;
}
double Vehicul::obtineGreutate() const {
    return greutate;
}
std::string Vehicul::obtineNumarInmatriculare() const{
    return numarInmatriculare;
} 


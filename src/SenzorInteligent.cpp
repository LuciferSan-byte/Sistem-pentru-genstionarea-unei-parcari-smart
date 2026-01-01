#include "SenzorInteligent.h"

SenzorInteligent::SenzorInteligent(int id): Senzor(id) {}

bool SenzorInteligent::proceseazaVehicul(const Vehicul &v){
    detecteaza();

    if(!captureazaImagine()){
	std::cout << "Eroare la capturarea imaginii \n";
	return false;
    }

    ultimulNumarDetectat = recunoasteNumar(v);

    std::cout << "Numar recunoscut: " << ultimulNumarDetectat << "\n";
    return true;

}

std::string SenzorInteligent::obtineUltimulNumar() const{
    return ultimulNumarDetectat;
}

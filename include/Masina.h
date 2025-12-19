#pragma once

#include <string>
#include "Vehicul.h"

class Masina : public Vehicul{
private:
    int numarUsi;
    std::string tipCombustibil;
    bool esteElectric;

public:
    Masina(
	int id,
	const std::string& numar,
	const Dimensiune& dim,
	double greutate,
	int numarUsi,
	std::string tipCombustibil,
	bool esteElectric
    );
    std::string categorieVehicul() const override; 
};

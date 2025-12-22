#pragma once

#include <string>
#include "Vehicul.h"

class Masina : public Vehicul{
private:
    int numarUsi;
    std::string tipCombustibil;
    bool electrica;

public:
    Masina(
	int id,
	const std::string& numar,
	const Dimensiune& dim,
	double greutate,
	int numarUsi,
	const std::string &tipCombustibil,
	bool esteElectric
    );
    bool esteElectric()const override; 
    std::string categorieVehicul() const override;
    int obtineNumarAxe()const override;
};

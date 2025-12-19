#pragma once

#include "Vehicul.h"

class Camion : public Vehicul{
private:
    double sarcinaMaxima;
    int numarAxe;

public:
    Camion(
	int id,
        const std::string& numar,
        const Dimensiune& dim,
        double greutate,
	double sarcinaMaxima,
        int numarAxe
	);
    
    std::string categorieVehicul() const override;
};

#pragma once

#include "Vehicul.h"

class Motocicleta : public Vehicul{
private:
    int capacitateMotor;
    bool areAtas;

public:
    Motocicleta(
	int id,
	const std::string& numar,
	const Dimensiune& dim,
	double greutate,
	int capacitateMotor,
        bool areAtas
    );

    std::string categorieVehicul() const override;
};

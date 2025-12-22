#pragma once 

#include <string>
#include "Dimensiune.h"

class Vehicul{
protected:
    int idVehicul;
    std::string numarInmatriculare;
    Dimensiune dimensiune;
    double greutate;
public:
    Vehicul(
	int id,
	const std::string& numar,
	const Dimensiune& dim,
	double greutate
    );
    virtual ~Vehicul() = default;
    Dimensiune obtineDimensiune()const;
    double obtineGreutate()const;
    
    virtual bool esteElectric()const  = 0;
    virtual std::string categorieVehicul() const  = 0;
    virtual int obtineNumarAxe()const = 0;
};

#pragma once

#include "Dimensiune.h"
#include "Vehicul.h"
#include "Sofer.h"
#include "Led.h"
#include "SenzorInteligent.h"

#include <iostream>
#include <vector>
#include <string>

class LocParcare{
protected:
    int idLoc;
    bool ocupat;
    bool electric;
    bool handicap;
    std::string vehiculAcceptat; 
    Dimensiune dimensiune;
    Led led;
    SenzorInteligent senzor;
public:
    LocParcare(int id);
    virtual ~LocParcare() = default;
    
    virtual bool incapeVehicul(const Vehicul& v) const;
    virtual bool acceptaVehicul(const Vehicul& v) const;
   
    void detecteazaVehicul();
    void vehiculPleaca();

    virtual bool esteElectric() const;
    virtual bool esteHandicap() const;
    std::string obtineVehiculAcceptat() const;
    Dimensiune obtineDimensiune() const;

    void ocupa();
    void elibereaza();
    bool esteOcupat() const;

    int obtineId() const;
    void afiseazaStare() const;
};

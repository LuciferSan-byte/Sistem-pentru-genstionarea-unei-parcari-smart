#pragma once

#include "Dimensiune.h"
#include "Vehicul.h"
#include "Sofer.h"
#include "Led.h"
#include "Senzor.h"

#include <iostream>
#include <vector>
class LocParcare{
protected:
    int idLoc;
    bool ocupat;
    std::string vehiculAcceptat; 
    Dimensiune dimensiune;
    Led led;
    Senzor senzor;
public:
    LocParcare(int id);
    virtual ~LocParcare() = default;
    
    virtual bool incapeVehicul(const Vehicul& v) const;
    virtual bool acceptaVehicul(const Vehicul& v) const;
    
    void detecteazaVehicul();
    void vehiculPleaca();

    void ocupa();
    void elibereaza();
    bool esteOcupat() const;

    void afiseazaStare() const;
};

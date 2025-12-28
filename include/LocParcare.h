#pragma once

#include "Dimensiune.h"
#include "Vehicul.h"
#include "Sofer.h"
#include <vector>
class LocParcare{
protected:
    int idLoc;
    bool ocupat;
    std::string vehiculAcceptat; 
    Dimensiune dimensiune;
public:
    LocParcare(int id);
    virtual ~LocParcare() = default;
    
    virtual bool incapeVehicul(const Vehicul& v) const;
    virtual bool acceptaVehicul(const Vehicul& v) const;
    
    void ocupa();
    void elibereaza();
    bool esteOcupat() const;
};

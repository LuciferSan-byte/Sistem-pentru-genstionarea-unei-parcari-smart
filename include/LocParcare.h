#pragma once

#include "Dimensiune.h"
#include "Vehicul.h"
class LocParcare{
protected:
    int idLoc;
    bool ocupat;
    Dimensiune dimensiune;
public:
    LocParcare(int id, const Dimensiune& dim);
    virtual ~LocParcare() = default;

    virtual bool incapeVehicul(const Vehicul& v) const;
    virtual bool acceptaVehicul(const Vehicul& v) const;

    void ocupa();
    void elibereaza();
    bool esteOcupat() const;
};

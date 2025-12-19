#pragma once

#include "LocParcare.h"

class LocParcareMotocicleta : public LocParcare {
private:
    int numarMaximMotociclete;

public:
    LocParcareMotocicleta(int id,
                          const Dimensiune& dim,
                          int numarMaximMotociclete);

    bool acceptaVehicul(const Vehicul& v) const override;
};


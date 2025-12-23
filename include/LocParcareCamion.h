#pragma once

#include "LocParcare.h"
#include <iostream>
class LocParcareCamion : public LocParcare {
private:
    double sarcinaMaxima;
    int numarAxePermise;

public:
    LocParcareCamion(int id,
                     double sarcinaMaxima,
                     int numarAxePermise);

    bool acceptaVehicul(const Vehicul& v) const override;
};


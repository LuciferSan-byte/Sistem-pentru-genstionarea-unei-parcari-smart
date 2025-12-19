#pragma once

#include "LocParcare.h"

class LocParcareElectric : public LocParcare {
private:
    double putereIncarcare;
    std::string tipConector;

public:
    LocParcareElectric(int id,
                       const Dimensiune& dim,
                       double putereIncarcare,
                       const std::string& tipConector);

    bool acceptaVehicul(const Vehicul& v) const override;

    void pornesteIncarcarea();
    void opresteIncarcarea();
};


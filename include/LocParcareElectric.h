#pragma once

#include "LocParcare.h"

class LocParcareElectric : public LocParcare {
private:
    double putereIncarcare;
    std::string tipConector;

public:
    LocParcareElectric(int id,
                       double putereIncarcare,
                       const std::string& tipConector);

    bool acceptaVehicul(const Vehicul& v) const override;

    void pornesteIncarcarea();
    void opresteIncarcarea();
};


#pragma once

#include "LocParcare.h"

class LocParcareHandicap : public LocParcare {
private:
    double latimeZonaAcces;
    bool aproapeIntrare;

public:
    LocParcareHandicap(int id,
                       const Dimensiune& dim,
                       double latimeZonaAcces,
                       bool aproapeIntrare);

    bool acceptaVehicul(const Vehicul& v) const override;
    bool esteAccesibil() const;
};


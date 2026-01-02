#pragma once

#include "LocParcare.h"

class LocParcareHandicap : public LocParcare {
private:
    double latimeZonaAcces;
    bool aproapeIntrare;

public:
    LocParcareHandicap(int id,
                       double latimeZonaAcces,
                       bool aproapeIntrare,
		       bool electric);

    bool acceptaVehicul(const Vehicul& v) const override;
    bool acceptaSofer(const Sofer& s)const;
    bool esteAccesibil() const;


};


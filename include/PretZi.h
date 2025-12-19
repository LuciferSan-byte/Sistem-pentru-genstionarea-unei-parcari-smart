#pragma once

#include "PoliticaPret.h"

class PretZi : public PoliticaPret {
private:
    double tarifOra;
    int oraStart;
    int oraStop;

public:
    PretZi(double tarifOra, int oraStart, int oraStop);
    double calculeazaPret(const Tichet& t,
                          const Vehicul& v) const override;
};


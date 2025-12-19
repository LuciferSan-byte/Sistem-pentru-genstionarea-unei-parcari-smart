#pragma once

#include "PoliticaPret.h"

class PretNoapte : public PoliticaPret {
private:
    double tarifOra;
    int oraStart;
    int oraStop;

public:
    PretNoapte(double tarifOra, int oraStart, int oraStop);
    double calculeazaPret(const Tichet& t,
                          const Vehicul& v) const override;
};


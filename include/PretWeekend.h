#pragma once

#include "PoliticaPret.h"

class PretWeekend : public PoliticaPret {
private:
    double tarifOra;
    int oraStart;
    int oraStop;

public:
    PretWeekend(double tarifOra, int oraStart, int oraStop);
    double calculeazaPret(const Tichet& t,
                          const Vehicul& v) const override;
};


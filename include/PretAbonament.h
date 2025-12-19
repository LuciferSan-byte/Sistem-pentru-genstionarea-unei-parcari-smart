#pragma once

#include "PoliticaPret.h"

class PretAbonament : public PoliticaPret {
private:
    double tarifOra;
    int oraStart;
    int oraStop;

public:
    PretAbonament(double tarifOra, int oraStart, int oraStop);
    double calculeazaPret(const Tichet& t,
                          const Vehicul& v) const override;
};


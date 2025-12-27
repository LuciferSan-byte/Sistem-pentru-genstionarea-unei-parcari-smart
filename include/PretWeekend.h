#pragma once

#include "PoliticaPret.h"

class PretWeekend : public PoliticaPret {
private:
    double tarifOra;
public:
    PretWeekend();
    double calculeazaPret(const Tichet& t)const override;
};


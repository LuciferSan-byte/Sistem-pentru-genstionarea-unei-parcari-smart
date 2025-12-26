#pragma once

#include "PoliticaPret.h"

class PretZi : public PoliticaPret {
private:
    double tarifOra;
public:
    PretZi();
    double calculeazaPret(const Tichet & t)const override;
                          
};


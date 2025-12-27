#pragma once

#include "PoliticaPret.h"

class PretNoapte : public PoliticaPret {
private:
    double tarifOra;
public:
    PretNoapte();
    double calculeazaPret(const Tichet& t)const override; 
};


#pragma once

#include "PoliticaPret.h"
#include <chrono>
#include <ctime>

class PretZi : public PoliticaPret {
private:
    double tarifOra;
    std::chrono::system_clock::time_point oraStart;
    std::chrono::system_clock::time_point oraStop;

public:
    PretZi(std::chrono::system_clock::time_point oraStart, std::chrono::system_clock::time_point oraStop);
    double calculeazaPret(const Tichet& t,
                          const Vehicul& v) const override;
};


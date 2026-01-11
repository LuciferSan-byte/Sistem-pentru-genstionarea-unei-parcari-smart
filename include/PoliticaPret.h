#pragma once
#include "Tichet.h"
#include <chrono>
#include <ctime>


class PoliticaPret{
public:
    virtual ~PoliticaPret() = default;
    virtual inline double calculeazaPret(const Tichet &t)const = 0;
};


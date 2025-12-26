#pragma once
#include "Tichet.h"
#include <chrono>
#include <ctime>


class PoliticaPret{
public:
    virtual ~PoliticaPret() = default;
    virtual double calculeazaPret(const Tichet &t)const = 0;
};


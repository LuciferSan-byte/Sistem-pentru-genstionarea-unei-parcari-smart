#pragma once

#include <string>
#include <vector>
#include "EtajParcare.h"

class Vehicul;
class LocParcare;

class Parcare {
private:
    std::string nume;
    std::vector<EtajParcare> etaje;

public:
    Parcare(const std::string& nume);

    void adaugaEtaj(const EtajParcare& etaj);
    LocParcare* cautaLoc(const Vehicul& v) const;
};


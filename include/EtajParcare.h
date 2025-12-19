#pragma once

#include <vector>

class LocParcare;
class Vehicul;

class EtajParcare {
private:
    int numarEtaj;
    std::vector<LocParcare*> locuriParcare;

public:
    EtajParcare(int numarEtaj);

    void adaugaLoc(LocParcare* loc);
    bool areLocLiber(const Vehicul& v) const;
    LocParcare* obtineLocLiber(const Vehicul& v) const;
};


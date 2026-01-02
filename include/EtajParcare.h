#pragma once

#include <vector>
#include <iostream>
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
    int  numarLocuriLibere() const;

    bool parcheazaPeLoc(int idLoc, const Vehicul &v) const;
    bool parcheazaAutomat(const Vehicul &v) const;
    
    void nrLocuriLiberePeCategorii() const;
    void afiseazaStareEtaj() const;
};


#pragma once

#include <vector>
#include <iostream>
#include "Tichet.h"

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
    
    bool verificaLocOcupat(const int & Id) const;

    bool parcheazaPeLoc(int idLoc, const Vehicul &v, Tichet &t) const;
    bool parcheazaAutomat(const Vehicul &v, Tichet & t) const;
    
    void nrLocuriLiberePeCategorii() const;
    void afiseazaStareEtaj() const;
   
    bool elibereazaLoc(int idLoc);
    int obtineNrEtaj() const;
};


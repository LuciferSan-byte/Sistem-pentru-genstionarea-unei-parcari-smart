#pragma once

#include <vector>
#include "Parcare.h"
#include "Tichet.h"
#include "Abonament.h"

class Vehicul;
class Sofer;
class LocParcare;

class SistemParcare {
private:
    Parcare parcare;
    std::vector<Tichet> ticheteActive;
    std::vector<Vehicul*> vehicule;
    std::vector<Abonament> abonamente;

public:
    SistemParcare(const Parcare& parcare);

    void inregistreazaVehicul(Vehicul* v);
    Tichet creeazaTichet(Vehicul* v);
    void inchideTichet(int idTichet);

    LocParcare* alocaLoc(const Vehicul& v);
    bool valideazaAcces(const Vehicul& v, const Sofer& s) const;
};


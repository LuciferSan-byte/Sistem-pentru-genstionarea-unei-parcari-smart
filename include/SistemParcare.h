#pragma once

#include <vector>
#include <unordered_map>

#include "EtajParcare.h"
#include "LocParcare.h"
#include "Vehicul.h"
#include "ControlPoarta.h"
#include "Tichet.h"
#include "PlataCard.h"
#include "PlataCash.h"
#include "PretZi.h"
#include "PretWeekend.h"
#include "PretNoapte.h"

class SistemParcare {
private:
    std::vector<EtajParcare*> etaje;
    std::vector<Tichet> ticheteActive;

    ControlPoarta barieraIntrare;
    ControlPoarta barieraIesire;
    
    PretZi politicaZi;
    PretNoapte politicaNoapte;
    PretWeekend politicaWeekend;

    int nextTichetId;
public:
    SistemParcare();

    void adaugaEtaj(EtajParcare* etaj);
    
    bool parcheazaPeLoc(Vehicul& v, int numarEtaj, int idLoc);
    bool parcheazaAutomat(Vehicul& v);

    Tichet& vehiculIntra(Vehicul& v);
    bool vehiculIese(int idTichet);
    
    PoliticaPret* alegePoliticaPret(const Tichet& t) const;
    bool proceseazaPlata(int idTichet);

};


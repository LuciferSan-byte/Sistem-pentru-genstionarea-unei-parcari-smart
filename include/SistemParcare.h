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
    
    int vehiculIntraAutomat(Vehicul& v);
    int vehiculIntraPeLoc(Vehicul& v,
                               int nrEtaj,
                               int idLoc);
 
    
    PoliticaPret* alegePoliticaPret(const Tichet& t) const;
    bool proceseazaPlata(int idTichet);
    bool vehiculIese(int idTichet);
};


#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

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
#include "Camera.h"

class SistemParcare {
private:
    std::vector<EtajParcare*> etaje;
    std::vector<Tichet> ticheteActive;
    std::unordered_set<Vehicul*> vehiculeParcate;

    ControlPoarta bariera;
    
    PretZi politicaZi;
    PretNoapte politicaNoapte;
    PretWeekend politicaWeekend;

    int nextTichetId;
public:
    SistemParcare();

    void adaugaEtaj(EtajParcare* etaj);
    
    int vehiculIntraAutomat(Vehicul& v, bool Handicap);
    int vehiculIntraPeLoc(Vehicul& v,
                               int nrEtaj,
                               int idLoc,
				bool Handicap);
 
    
    PoliticaPret* alegePoliticaPret(const Tichet& t) const;
    bool proceseazaPlata(int idTichet);
    bool vehiculIese(int idTichet);
};


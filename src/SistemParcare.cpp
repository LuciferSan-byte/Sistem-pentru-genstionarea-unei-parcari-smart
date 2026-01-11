#include "SistemParcare.h"



SistemParcare::SistemParcare() : nextTichetId(1) 
{
    std::cout << "SistemParcare initializat\n\n";
}

void SistemParcare::adaugaEtaj(EtajParcare *etaj){
    if (!etaj) return;
    etaje.push_back(etaj);
}

int SistemParcare::vehiculIntraAutomat(Vehicul& v, bool Handicap) {

    
    if (vehiculeParcate.count(&v)) {
	throw std::runtime_error("Vehiculul este deja parcat");
    }
    
    Tichet t(nextTichetId++);
    t.seteazaVehicul(&v);

    bariera.deschide();
    std::cout << "Masina intra in parcare";
    bariera.inchide();
    for (auto& etaj : etaje) {
        if (etaj->parcheazaAutomat(v, t, Handicap)) {
	    
            ticheteActive.push_back(t);

	    vehiculeParcate.insert(&v);
            return ticheteActive.back().obtineId();
        }
    }

    throw std::runtime_error("Nu exista loc liber");
}

int SistemParcare::vehiculIntraPeLoc(Vehicul& v,
                                         int nrEtaj,
                                         int idLoc,
					 bool Handicap)
{
     if (vehiculeParcate.count(&v)) {
	throw std::runtime_error("Vehiculul este deja parcat");	
    }
    Tichet t(nextTichetId++);
    t.seteazaVehicul(&v);
    

    bariera.deschide();
    std::cout << "Vehicul intra in parcare";
    bariera.inchide();

    for (auto& etaj : etaje) {
        if (etaj->obtineNrEtaj() == nrEtaj) {

            if (!etaj->parcheazaPeLoc(idLoc, v, t, Handicap)) {
		std::cout << "\nParcare manuala esuata\n";
		nextTichetId--;
		throw std::runtime_error("Locul nu exista");	
		
	    }

            ticheteActive.push_back(t);

	    vehiculeParcate.insert(&v);
            return ticheteActive.back().obtineId();
        }
    }
    nextTichetId--;
    throw std::runtime_error("Etaj inexistent");
}

bool SistemParcare::vehiculIese(int idTichet) {
    for (auto it = ticheteActive.begin(); it != ticheteActive.end(); ++it) {

        if (it->obtineId() == idTichet) {

            if (!it->esteInchis()) {
                std::cout << "Plata nu a fost efectuata!\n";
                return false;
            }

            int idLoc = it->obtineIdLoc();

            for (auto& etaj : etaje) {
                if (etaj->elibereazaLoc(idLoc)) {
                    break;
                }
            }

            bariera.deschide();
            ticheteActive.erase(it);

            std::cout << "Vehicul poate iesi din parcare\n";
            return true;
        }
    }

    std::cout << "Tichet inexistent\n";
    return false; 
}

bool SistemParcare::proceseazaPlata(int idTichet) {
    for (auto it = ticheteActive.begin();
         it != ticheteActive.end(); ++it)
    {
        if (it->obtineId() == idTichet)
        {
            int minute;
            std::cout << "Cate minute doriti sa stati in parcare? ";
            std::cin >> minute;

            if (minute <= 0) {
                std::cout << "Durata invalida!\n";
                return false;
            }

            it->seteazaDurataMinute(minute);

            PoliticaPret* politica = alegePoliticaPret(*it);
            double suma = politica->calculeazaPret(*it);
            it->seteazaSuma(suma);

            std::cout << "\n===== PLATA PARCARE =====\n";
            it->afiseazaSuma();

            bool plataReusita = false;
            while (!plataReusita) {
                std::cout << "\n[1] Cash\n[2] Card\n> ";
                int opt;
                std::cin >> opt;

                if (opt == 1) {
                    PlataCash cash;
                    plataReusita = cash.efectueazaPlata(suma);
                }
                else if (opt == 2) {
                    PlataCard card;
                    plataReusita = card.efectueazaPlata(suma);
                }
                else {
                    std::cout << "Optiune invalida\n";
                }
            }

            std::cout << "Plata efectuata cu succes\n";

            int idLoc = it->obtineIdLoc();
	    

	    Vehicul* v = it->obtineVehicul();
	    vehiculeParcate.erase(v);

            it->inchide();
            ticheteActive.erase(it);

            for (auto& etaj : etaje) {
                if (etaj->elibereazaLoc(idLoc)) {
                    break;
                }
            }

            bariera.deschide();

            std::cout << "Vehicul poate iesi din parcare\n";
            return true;
        }
    }

    std::cout << "Tichet inexistent\n";
    return false;   
}


PoliticaPret* SistemParcare::alegePoliticaPret(const Tichet& t) const {
    using clock = std::chrono::system_clock;

    std::time_t tt = clock::to_time_t(t.obtineOraIntrare());
    std::tm local = *std::localtime(&tt);

    if (local.tm_wday == 0 || local.tm_wday == 6) {
        return const_cast<PretWeekend*>(&politicaWeekend);
    }

    if (local.tm_hour >= 22 || local.tm_hour < 6) {
        return const_cast<PretNoapte*>(&politicaNoapte);
    }

    return const_cast<PretZi*>(&politicaZi); 
}

#include "SistemParcare.h"

SistemParcare::SistemParcare() : nextTichetId(1) 
{
    std::cout << "SistemParcare initializat\n\n";
}

void SistemParcare::adaugaEtaj(EtajParcare *etaj){
    if (!etaj) return;
    etaje.push_back(etaj);
}

bool SistemParcare::parcheazaPeLoc(Vehicul& v, int numarEtaj, int idLoc) {
    for (auto& etaj : etaje) {
        if (etaj->obtineNrEtaj() == numarEtaj) {
	    if(!etaj->verificaLocOcupat(idLoc)){
		return false;
	    }
            if (!etaj->parcheazaPeLoc(idLoc, v)) {
		std::cout << "Nu s-a putut parca\n";
		return false;
            }
	    std::cout <<"Vehicul parcat cu succes\n";
	    return true;
        }
    }

    std::cout << "Etaj inexistent.\n";
    return false;
}

bool SistemParcare::parcheazaAutomat(Vehicul& v) {
    for (auto& etaj : etaje) {
        if (etaj->areLocLiber(v)) {
            return etaj->parcheazaAutomat(v);
        }
    }

    std::cout << "Nu exista loc liber\n";
    return false;
}

Tichet& SistemParcare::vehiculIntra(Vehicul& v) {

    if (!parcheazaAutomat(v)) {
        throw std::runtime_error("Intrare refuzata: nu exista loc");
    }

    Tichet t(nextTichetId++);
    t.seteazaVehicul(&v);
    ticheteActive.push_back(t);

    barieraIntrare.deschide();

    std::cout << "Vehicul intrat. Tichet ID: "
              << ticheteActive.back().obtineId() << "\n";

    return ticheteActive.back();
}

bool SistemParcare::vehiculIese(int idTichet) {
    for (auto it = ticheteActive.begin();
         it != ticheteActive.end(); ++it) {

        if (it->obtineId() == idTichet) {

            it->seteazaOraIesire();
            ticheteActive.erase(it);

            barieraIesire.deschide();
            std::cout << "Vehicul iesit\n";
            return true;
        }
    }

    std::cout << "Tichet invalid\n";
    return false;
}

bool SistemParcare::proceseazaPlata(int idTichet) {
  
    for (auto it = ticheteActive.begin();
         it != ticheteActive.end(); ++it) {

        if (it->obtineId() == idTichet) {

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

            it->inchide();
            ticheteActive.erase(it);
            barieraIesire.deschide();
	    
	    for (auto& etaj : etaje) {
	       if (etaj->elibereazaLoc(it->obtineIdLoc())) {
		    break;
		}
	    }	
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

#include "EtajParcare.h"
#include "Vehicul.h"
#include "LocParcare.h"

EtajParcare::EtajParcare(int numarEtaj) : numarEtaj(numarEtaj){}

void EtajParcare::adaugaLoc(LocParcare* loc){
    if(!loc) return;
    locuriParcare.push_back(loc);
}


bool EtajParcare::parcheazaPeLoc(int idLoc, const Vehicul & v, Tichet &t, bool Handicap) const{
    for(auto& loc : locuriParcare) {
	if(loc->obtineId() == idLoc){
	    
	    if(loc->esteOcupat()){
		std::cout << "Locul " << loc->obtineId() << " este deja ocupat\n";
		return false;
	    }
	    std::cout << "siuuuuuuuu2";
	if(!loc->acceptaVehicul(v)){
	    std::cout << "Vehiculul nu este acceptat pe locul " << loc->obtineId() << "\n";
	    return false;
	}

	if(loc->esteHandicap() == true){
	    if(Handicap == false){
		std::cout << "Locul este destinat persoanelor cu dizabilitati";
		return false;
		}
	}
	loc->detecteazaVehicul();
	std::cout << "Vehicul parcat pe locul ales: " << idLoc << "\n";
	t.seteazaIdLoc(loc->obtineId());
	return true;
	}
    }

    std::cout << "Locul nu exista \n";
    return false;
}

bool EtajParcare::parcheazaAutomat(const Vehicul &v, Tichet &t, bool Handicap) const{
    for(auto &loc : locuriParcare){
	if(!loc->esteOcupat() && loc->acceptaVehicul(v)){
	   
	    std::cout << "Vehicul parcat automat pe locul "
		      << loc->obtineId() << "\n";

	    loc->detecteazaVehicul();              
	    t.seteazaIdLoc(loc->obtineId());       
	    return true;
	}
    }
    std::cout << "Nu s-a gasit un loc potrivit \n";
    return false;
}

bool EtajParcare::areLocLiber(const Vehicul & v, int id) const{
    for(const auto & loc : locuriParcare){
	if(loc->obtineId() == id){
	if(!loc->esteOcupat() && loc->acceptaVehicul(v)){
	    std::cout << "Vehicul poate parca pe locul cu ID: " << id;
	    return true;
	}
	}
    }
    std::cout << "Vehicul nu poate parca pe locul cu ID: " << id;
    return false;
}

int EtajParcare::numarLocuriLibere() const{
    int count = 0;
    for(const auto& loc : locuriParcare){
	if(!loc->esteOcupat()){
	    count++;
	}
    }
    return count;
}




void EtajParcare::nrLocuriLiberePeCategorii() const{
    int nrLocuriElectric = 0;
    int nrLocuriMasina = 0;
    int nrLocuriMoto = 0;
    int nrLocuriCamion = 0;
    int nrLocuriHandicap = 0;
    int nrLocuriHandicapElectric = 0;

    std::cout << "=== Etaj " << numarEtaj << " ===\n";

    for (const auto& loc : locuriParcare) {
	if(!loc->esteOcupat()){
        std::string tip = loc->obtineVehiculAcceptat();

        if (tip == "Masina") {
            if (loc->esteHandicap()) {
                if (loc->esteElectric())
                    nrLocuriHandicapElectric++;
                else
                    nrLocuriHandicap++;
            } else {
                if (loc->esteElectric())
                    nrLocuriElectric++;
                else
                    nrLocuriMasina++;
            }
        }
        else if (tip == "Motocicleta") {
            nrLocuriMoto++;
        }
        else if (tip == "Camion") {
            nrLocuriCamion++;
        }
    }
    }
    std::cout << "Locuri libere: " << numarLocuriLibere() << "\n\n";
    std::cout << "Nr locuri masina: " << nrLocuriMasina << "\n"
              << "Nr locuri electric: " << nrLocuriElectric << "\n"
              << "Nr locuri handicap: " << nrLocuriHandicap << "\n"
              << "Nr locuri handicap electrice: " << nrLocuriHandicapElectric << "\n"
              << "Nr locuri moto: " << nrLocuriMoto << "\n"
              << "Nr locuri camion: " << nrLocuriCamion << "\n";
}

void EtajParcare::afiseazaStareEtaj() const{
    std::cout << "=== Etaj " << numarEtaj << " ===\n";
   
    for(auto & loc : locuriParcare){
	loc->afiseazaStare();
	
	std::cout << "Tip loc: " << loc->obtineVehiculAcceptat() << "\n";
	
	std::cout << "Electric: ";
	std::cout << (loc->esteElectric() ? "Da" : "Nu");
	std::cout << "\n";

	if(loc->obtineVehiculAcceptat() == "Masina"){
	    std::cout << "Loc pentru persoane cu handicap: ";
	    std::cout << (loc->esteHandicap() ? "Da" : "Nu");
	    std::cout << "\n";
	}

	std::cout << "\n\n-----------------\n\n";
	}
    }

int EtajParcare::obtineNrEtaj() const { return numarEtaj;}

bool EtajParcare::verificaLocOcupat(const int & Id) const {
    for(auto &loc : locuriParcare){
	if(Id == loc->obtineId())
	    if(loc->esteOcupat() == false){
		std::cout << "Locul este liber ";
		return true;
	    }
	    else{
		std::cout << "Loc ocupat\n ";
		return false;
	    }
    }
    std::cout << "Loc inexistent\n";
    return false;
}

bool EtajParcare::elibereazaLoc(int idLoc) {
      for (auto& loc : locuriParcare) {
        if (loc->obtineId() == idLoc) {

            if (!loc->esteOcupat()) {
                return false;
            }

            loc->vehiculPleaca();
            std::cout << "Locul " << idLoc << " a fost eliberat\n";
            return true;
        }
    }
    return false;
}

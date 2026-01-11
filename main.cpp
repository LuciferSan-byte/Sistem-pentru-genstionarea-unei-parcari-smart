#include <iostream>
#include <iomanip>

#include "Sofer.h"

#include "Masina.h"
#include "Motocicleta.h"
#include "Camion.h"

#include "LocParcare.h"
#include "LocParcareElectric.h"
#include "LocParcareCamion.h"
#include "LocParcareMotocicleta.h"
#include "LocParcareHandicap.h"

#include "Tichet.h"
#include "PoliticaPret.h"
#include "PretZi.h"
#include "PretNoapte.h"
#include "PretWeekend.h"

#include "PlataCard.h"
#include "PlataCash.h"

#include "Camera.h"
#include "Senzor.h"
#include "SenzorInteligent.h"
#include "EtajParcare.h"
#include "SistemParcare.h"

#include <thread>

#include <cstdlib>

void clearScreen(int cooldown_ms = 500) {

std::this_thread::sleep_for(std::chrono::milliseconds(cooldown_ms));

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void afiseazaStareParcare(const std::vector<EtajParcare*>& etaje) {
     while (true) {
        std::cout << "\n===== STARE PARCARE =====\n";
        std::cout << "1. Afiseaza starea intregii parcari\n";
	std::cout << "2. Afiseaza stare parter\n";
        std::cout << "3. Afiseaza starea etaj 1\n";
        std::cout << "4. Afiseaza starea etaj 2\n";
        std::cout << "0. Inapoi la meniu\n> ";

        int opt;
        if (!(std::cin >> opt)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Introdu un NUMAR valid!\n";
            continue;
        }

        if (opt == 0) {
            return;
        }
        else if (opt == 1) {
	    clearScreen();
            for (auto e : etaje)
                e->afiseazaStareEtaj();
        }
        else if (opt == 2) {
	    clearScreen();
            if (etaje.size() >= 1)
                etaje[0]->afiseazaStareEtaj();
        }
        else if (opt == 3) {
	    clearScreen();
            if (etaje.size() >= 2)
                etaje[1]->afiseazaStareEtaj();
        }
	else if (opt == 4) {
	    clearScreen();
            if (etaje.size() >= 2)
                etaje[2]->afiseazaStareEtaj();
        }
        else {
            std::cout << "Optiune invalida\n";
	    clearScreen();
        }
	std::cout << "=========================\n";
    }
       
}

static void afiseazaVehicule(const std::vector<Vehicul*>& vehicule) {
    std::cout << "\n===== VEHICULE CREATE =====\n";
    if (vehicule.empty()) {
        std::cout << "(nimic)\n";
        return;
    }
    for (size_t i = 0; i < vehicule.size(); ++i) {
        std::cout << i << ". " << vehicule[i]->categorieVehicul()
                  << " | Nr: " << vehicule[i]->obtineNumarInmatriculare()
                  << "\n";
    }
}

int main() {

    SistemParcare sistem;
    Camera camera;
    SenzorInteligent senzor(1);
    std::vector<Vehicul*> vehicule;
    int nextVehiculId = 1;

    auto* parter = new EtajParcare(0);
    auto* etaj1  = new EtajParcare(1);
    auto* etaj2  = new EtajParcare(2);


    for (int i = 1; i <= 6; ++i)
	parter->adaugaLoc(new LocParcare(i));              //masini 

    parter->adaugaLoc(new LocParcareElectric(7, 22.0, "Type2"));
    parter->adaugaLoc(new LocParcareElectric(8, 22.0, "Type2"));

    parter->adaugaLoc(new LocParcareMotocicleta(9, 1));
    parter->adaugaLoc(new LocParcareMotocicleta(10, 1));

    parter->adaugaLoc(new LocParcareCamion(11, 12.0, 4));
    parter->adaugaLoc(new LocParcareCamion(12, 12.0, 4));

    parter->adaugaLoc(new LocParcareHandicap(13, 1.5, true, false));
    parter->adaugaLoc(new LocParcareHandicap(14, 1.5, true, true));

    for (int i = 101; i <= 106; ++i)
	etaj1->adaugaLoc(new LocParcare(i));                 // masini

    etaj1->adaugaLoc(new LocParcareElectric(107, 22.0, "Type2"));
    etaj1->adaugaLoc(new LocParcareElectric(108, 22.0, "Type2"));

    etaj1->adaugaLoc(new LocParcareMotocicleta(109, 1));
    etaj1->adaugaLoc(new LocParcareMotocicleta(110, 1));

    etaj1->adaugaLoc(new LocParcareCamion(111, 12.0, 4));
    etaj1->adaugaLoc(new LocParcareCamion(112, 12.0, 4));

    etaj1->adaugaLoc(new LocParcareHandicap(113, 1.4, false, false));
    etaj1->adaugaLoc(new LocParcareHandicap(114, 1.4, false, true));

    for (int i = 201; i <= 205; ++i)
	etaj2->adaugaLoc(new LocParcare(i));                 // masini

    etaj2->adaugaLoc(new LocParcareElectric(206, 22.0, "Type2"));

    etaj2->adaugaLoc(new LocParcareMotocicleta(207, 1));
    etaj2->adaugaLoc(new LocParcareMotocicleta(208, 1));

    etaj2->adaugaLoc(new LocParcareCamion(209, 12.0, 6));
    etaj2->adaugaLoc(new LocParcareCamion(210, 12.0, 6));

    etaj2->adaugaLoc(new LocParcareHandicap(211, 1.6, false, false));
    etaj2->adaugaLoc(new LocParcareHandicap(212, 1.6, false, true));

    sistem.adaugaEtaj(parter);
    sistem.adaugaEtaj(etaj1);
    sistem.adaugaEtaj(etaj2);

   
    std::vector<EtajParcare*> etaje = {parter , etaj1, etaj2};

    bool ruleaza = true;
    while (ruleaza) {

        std::cout << "\n===== MENIU =====\n";
        std::cout << "1. Creeaza vehicul\n";
        std::cout << "2. Parcare AUTOMATA\n";
        std::cout << "3. Parcare PE LOC\n";
        std::cout << "4. Scoate vehicul (plata)\n";
        std::cout << "5. Afiseaza STARE parcare\n";
	std::cout << "6. Afiseaza numar locuri libere pe categorii\n";
	std::cout << "7. Afiseaza numar locuri libere\n";
	std::cout << "8. Verificare status loc\n";
	std::cout << "9. Verificare loc liber pentru vehicul\n";
        std::cout << "0. Iesire\n> ";

        int opt;
	
	if (!(std::cin >> opt)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Introdu un NUMAR valid!\n" << std::flush;
        continue;
	}
	else if (opt == 0) {
            ruleaza = false;
        }

        else if (opt == 1) {
	    int tip;

	while (true) {
	    std::cout << "\nTip vehicul:\n";
	    std::cout << "1. Masina\n";
	    std::cout << "2. Motocicleta\n";
	    std::cout << "3. Camion\n> ";

	    if (std::cin >> tip) {
		if (tip >= 1 && tip <= 3) {
		    break;
		} else {
		    std::cout << "Alege un numar intre 1 si 3!\n";
		}
	    } else {
		std::cout << "Introdu un NUMAR valid!\n";
		std::cin.clear();
	    }

	    std::cin.ignore(1000, '\n'); 
	    } 

            std::string nr;
            std::cout << "Numar inmatriculare: ";
            std::cin >> nr;

            Vehicul* v = nullptr;
	    
	    bool decizie_elec;
            if (tip == 1) {
		
		std::cout << "Masina este electrica?\n";
		std::cout << "0. Nu\n";
		std::cout << "1. Da\n> ";

		while (!(std::cin >> decizie_elec) || (decizie_elec != 0 && decizie_elec != 1)) {
		    std::cout << "Introdu 0 (Nu) sau 1 (Da)!\n";
		    std::cin.clear();
		    std::cin.ignore(1000, '\n');
		}


                v = new Masina(
                    nextVehiculId++,
                    nr,
                    Dimensiune::pentruLocMasina(), 
                    1400,
                    4,
                    "benzina",
                    decizie_elec
                );
            } else if (tip == 2) {
                v = new Motocicleta(
                    nextVehiculId++,
                    nr,
                    Dimensiune::pentruLocMoto(), 
                    200,
                    1,
                    false
                );
            } else if (tip == 3) {
                v = new Camion(
                    nextVehiculId++,
                    nr,
                    Dimensiune::pentruLocCamion(), 
                    8000,
                    12.0,
                    4
                );
            } else {
                std::cout << "Tip invalid\n";
            }

            if (v) {
                vehicule.push_back(v);
                std::cout << "Vehicul creat cu index " << (vehicule.size() - 1) << "\n";
            }
	    clearScreen();
        }

        else if (opt == 2) {
            if (vehicule.empty()) {
                std::cout << "Nu exista vehicule create\n";
                continue;
            }

            afiseazaVehicule(vehicule);

            int index;
	    
	    while (true) {
		std::cout << "Index vehicul (0.." << vehicule.size() - 1 << "): ";

		if (std::cin >> index) {
		    if (index >= 0 && index < static_cast<int>(vehicule.size())) {
			break; 
		    } else {
			std::cout << "Index in afara intervalului!\n";
		    }
		} else {
		    std::cout << "Introdu un NUMAR valid!\n";
		    std::cin.clear();
		}

		std::cin.ignore(1000, '\n');
	    }


            try {
		camera.captureazaImagine();
		camera.recunoasteNumar(*vehicule[index]);
		int opt;
		bool permisHandicap;

		while (true) {
		    std::cout << "Soferul detine permis pentru persoane cu dizabilitati?\n";
		    std::cout << "0. Nu\n";
		    std::cout << "1. Da\n> ";

		    if (std::cin >> opt) {
			if (opt == 0 || opt == 1) {
			    permisHandicap = static_cast<bool>(opt);
			    break;
			} else {
			    std::cout << "Alege 0 (Nu) sau 1 (Da)!\n";
			}
		    } else {
			std::cout << "Introdu un NUMAR valid!\n";
			std::cin.clear();
		    }

		    std::cin.ignore(1000, '\n');
		}	
	    
		    int idTichet = sistem.vehiculIntraAutomat(*vehicule[index], permisHandicap);
		    std::cout << "\nParcare automata reusita. Tichet ID: " << idTichet << "\n";
		} catch (const std::exception& e) {
		    std::cout << "Eroare: " << e.what() << "\n";
            }
        }

        else if (opt == 3) {
            if (vehicule.empty()) {
                std::cout << "Nu exista vehicule create\n";
                continue;
            }

            afiseazaVehicule(vehicule);

            int index, nrEtaj, idLoc;
	    while (true) {
		std::cout << "Index vehicul (0.." << vehicule.size() - 1 << "): ";

		if (std::cin >> index) {
		    if (index >= 0 && index < static_cast<int>(vehicule.size())) {
			break; 
		    } else {
			std::cout << "Index in afara intervalului!\n";
		    }
		} else {
		    std::cout << "Introdu un NUMAR valid!\n";
		    std::cin.clear();
		}

		std::cin.ignore(1000, '\n');
	    } 

            std::cout << "Numar etaj: ";
            std::cin >> nrEtaj;
            std::cout << "ID loc: ";
            std::cin >> idLoc;

            try {
		camera.captureazaImagine();
		camera.recunoasteNumar(*vehicule[index]);
		int opt;
		bool permisHandicap;
		while (true) {
		    std::cout << "Soferul detine permis pentru persoane cu dizabilitati?\n";
		    std::cout << "0. Nu\n";
		    std::cout << "1. Da\n> ";

		    if (std::cin >> opt) {
			if (opt == 0 || opt == 1) {
			    permisHandicap = static_cast<bool>(opt);
			    break;
			} else {
			    std::cout << "Alege 0 (Nu) sau 1 (Da)!\n";
			}
		    } else {
			std::cout << "Introdu un NUMAR valid!\n";
			std::cin.clear();
		    }

		    std::cin.ignore(1000, '\n');
		}	


                int idTichet = sistem.vehiculIntraPeLoc(*vehicule[index], nrEtaj, idLoc, permisHandicap);
                std::cout << "\nParcare pe loc reusita. Tichet ID: " << idTichet << "\n";
            } catch (const std::exception& e) {
                std::cout << "Eroare: " << e.what() << "\n";
            }
        }

        else if (opt == 4) {
            int id;
	     if (vehicule.empty()) {
                std::cout << "Nu exista vehicule in parcare\n";
                continue;
            }
            std::cout << "ID Tichet: ";
            std::cin >> id;

            sistem.proceseazaPlata(id);
        }

        else if (opt == 5) {
	    clearScreen();
            afiseazaStareParcare(etaje);
        }
	else if (opt == 6) {
	    clearScreen();
	   for(auto& etaj : etaje){
		std::cout << "\n";
		etaj->nrLocuriLiberePeCategorii();
	    }
        }
	else if (opt == 7) {
	    clearScreen();
	  for(auto& etaj : etaje){
		std::cout << "\n=== Etaj " << etaj -> obtineNrEtaj() << "=== \nlocuri libere: " << etaj -> numarLocuriLibere();
		std::cout << "\n";
	    } 
        }
	else if (opt == 8) {
	    int nrEtaj, idLoc;
	    std::cout << "\nIntrodu numarul etajului: "; std::cin >> nrEtaj;
	    std::cout << "\nIntrodu id-ul locului: "; std::cin >> idLoc;
	    std::cout << "\n";
	    for(auto& etaj : etaje){
		if(etaj -> obtineNrEtaj() == nrEtaj){
		    etaj->verificaLocOcupat(idLoc);
		}
	    }
        }
	else if (opt == 9) {
	    clearScreen();
	  if (vehicule.empty()) {
                std::cout << "Nu exista vehicule create\n";
                continue;
            }

            afiseazaVehicule(vehicule);

            int index;
            std::cout << "Index vehicul (0.." << (vehicule.size() - 1) << "): ";
            std::cin >> index;

            if (index < 0 || index >= (int)vehicule.size()) {
                std::cout << "Index invalid\n";
                continue;
            }
	    int nrEtaj, idLoc;
	    std::cout << "Numar etaj: ";
            std::cin >> nrEtaj;
            std::cout << "ID loc: ";
            std::cin >> idLoc; 
	    
	    std::cout << "\n";
	    for(auto& etaj : etaje){
		if(etaj -> obtineNrEtaj() == nrEtaj)
		    etaj -> areLocLiber(*vehicule[index], idLoc);
	    }
 
        }
        else {
            std::cout << "Optiune invalida\n";
        }
    }

    for (auto v : vehicule) delete v;

 

    std::cout << "\n===== PROGRAM INCHIS =====\n";
    return 0;  
}

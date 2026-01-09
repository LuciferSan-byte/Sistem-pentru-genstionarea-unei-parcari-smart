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

    static void afiseazaStareParcare(const std::vector<EtajParcare*>& etaje) {
    std::cout << "\n===== STARE PARCARE =====\n";
    for (auto e : etaje) {
        if (!e) continue;
        e->afiseazaStareEtaj();
    }
    std::cout << "=========================\n";
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
    std::cout << "===== MENIU PARCARE =====\n\n";

    SistemParcare sistem;
    std::vector<Vehicul*> vehicule;
    int nextVehiculId = 1;


    auto* etaj1 = new EtajParcare(1);
    auto* etaj2 = new EtajParcare(2);

    auto* loc101 = new LocParcare(101);
    auto* loc102 = new LocParcare(102);
    auto* loc103 = new LocParcareMotocicleta(103, 1);
    auto* loc104 = new LocParcareCamion(104, 10.0, 4);

    etaj1->adaugaLoc(loc101);
    etaj1->adaugaLoc(loc102);
    etaj1->adaugaLoc(loc103);
    etaj1->adaugaLoc(loc104);

    auto* loc201 = new LocParcare(201);
    auto* loc202 = new LocParcare(202);
    auto* loc203 = new LocParcareMotocicleta(203, 1);
    auto* loc204 = new LocParcareCamion(204, 12.0, 6);

    etaj2->adaugaLoc(loc201);
    etaj2->adaugaLoc(loc202);
    etaj2->adaugaLoc(loc203);
    etaj2->adaugaLoc(loc204);

    sistem.adaugaEtaj(etaj1);
    sistem.adaugaEtaj(etaj2);

    std::vector<EtajParcare*> etaje = {etaj1, etaj2};

    bool ruleaza = true;
    while (ruleaza) {
        std::cout << "\n===== MENIU =====\n";
        std::cout << "1. Creeaza vehicul\n";
        std::cout << "2. Parcare AUTOMATA\n";
        std::cout << "3. Parcare PE LOC\n";
        std::cout << "4. Scoate vehicul (plata)\n";
        std::cout << "5. Afiseaza STARE parcare\n";
        std::cout << "0. Iesire\n> ";

        int opt;
        std::cin >> opt;

        if (opt == 0) {
            ruleaza = false;
        }

        else if (opt == 1) {
            int tip;
            std::cout << "\nTip vehicul:\n";
            std::cout << "1. Masina\n";
            std::cout << "2. Motocicleta\n";
            std::cout << "3. Camion\n> ";
            std::cin >> tip;

            std::string nr;
            std::cout << "Numar inmatriculare: ";
            std::cin >> nr;

            Vehicul* v = nullptr;

            if (tip == 1) {
                v = new Masina(
                    nextVehiculId++,
                    nr,
                    Dimensiune::pentruLocMasina(), 
                    1400,
                    4,
                    "benzina",
                    false
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
        }

        else if (opt == 2) {
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

            try {
                int idTichet = sistem.vehiculIntraAutomat(*vehicule[index]);
                std::cout << "Parcare automata reusita. Tichet ID: " << idTichet << "\n";
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
            std::cout << "Index vehicul: ";
            std::cin >> index;

            if (index < 0 || index >= (int)vehicule.size()) {
                std::cout << "Index invalid\n";
                continue;
            }

            std::cout << "Numar etaj: ";
            std::cin >> nrEtaj;
            std::cout << "ID loc: ";
            std::cin >> idLoc;

            try {
                int idTichet = sistem.vehiculIntraPeLoc(*vehicule[index], nrEtaj, idLoc);
                std::cout << "Parcare pe loc reusita. Tichet ID: " << idTichet << "\n";
            } catch (const std::exception& e) {
                std::cout << "Eroare: " << e.what() << "\n";
            }
        }

        else if (opt == 4) {
            int id;
            std::cout << "ID Tichet: ";
            std::cin >> id;

            sistem.proceseazaPlata(id);
        }

        else if (opt == 5) {
            afiseazaStareParcare(etaje);
        }

        else {
            std::cout << "Optiune invalida\n";
        }
    }

    for (auto v : vehicule) delete v;

 

    std::cout << "\n===== PROGRAM INCHIS =====\n";
    return 0;  
}

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

int main() {
    
    std::cout << "===== TEST ELIBERARE LOCURI =====\n\n";

    // =========================
    // INITIALIZARE SISTEM
    // =========================
    SistemParcare sistem;

    // =========================
    // CREARE ETAJ
    // =========================
    EtajParcare etaj1(1);

    // =========================
    // CREARE LOCURI
    // =========================
    LocParcare loc101(101);
    LocParcare loc102(102);
    LocParcare loc103(103);

    etaj1.adaugaLoc(&loc101);
    etaj1.adaugaLoc(&loc102);
    etaj1.adaugaLoc(&loc103);

    sistem.adaugaEtaj(&etaj1);

    // =========================
    // CREARE VEHICULE
    // =========================
    Masina masina1(
        1,
        "B111AAA",
        {4.2, 1.8, 1.6},
        1400,
        4,
        "benzina",
        false
    );

    Masina masina2(
        2,
        "B222BBB",
        {4.3, 1.9, 1.6},
        1500,
        4,
        "diesel",
        false
    );

    Masina masina3(
        3,
        "B333CCC",
        {4.1, 1.7, 1.5},
        1300,
        4,
        "benzina",
        false
    );

    // =====================================================
    // INTRARE VEHICULE
    // =====================================================
    std::cout << "\n--- INTRARE VEHICULE ---\n";

    Tichet& t1 = sistem.vehiculIntra(masina1);
    Tichet& t2 = sistem.vehiculIntra(masina2);
    Tichet& t3 = sistem.vehiculIntra(masina3);

    std::cout << "\nStare dupa intrari:\n";
    etaj1.afiseazaStareEtaj();

    // =====================================================
    // IESIRE VEHICULE (ORDINE DIFERITA)
    // =====================================================
    std::cout << "\n--- IESIRE VEHICUL 2 ---\n";
    sistem.proceseazaPlata(t2.obtineId());

    std::cout << "\nStare dupa iesire masina 2:\n";
    etaj1.afiseazaStareEtaj();

    std::cout << "\n--- IESIRE VEHICUL 1 ---\n";
    sistem.proceseazaPlata(t1.obtineId());

    std::cout << "\nStare dupa iesire masina 1:\n";
    etaj1.afiseazaStareEtaj();

    std::cout << "\n--- IESIRE VEHICUL 3 ---\n";
    sistem.proceseazaPlata(t3.obtineId());

    std::cout << "\nStare finala etaj:\n";
    etaj1.afiseazaStareEtaj();

    std::cout << "\n===== TEST FINALIZAT CU SUCCES =====\n";
   
}


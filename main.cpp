#include "Vehicul.h"
#include "Masina.h"
#include "Dimensiune.h"
#include "Motocicleta.h"
#include "Camion.h"
#include "LocParcare.h"
#include "LocParcareElectric.h"
#include "LocParcareCamion.h"
#include "Abonament.h"
#include "Sofer.h"
#include <iostream>
int main(){
    std::cout << "===== TEST DIMENSIUNI STATIC =====\n";

    Dimensiune dimLocMasina = Dimensiune::pentruLocMasina();
    Dimensiune dimLocCamion = Dimensiune::pentruLocCamion();
    Dimensiune dimLocMoto   = Dimensiune::pentruLocMoto();

    // =========================
    // VEHICULE
    // =========================
    Vehicul* masinaElectrica = new Masina(
        1,
        "B123ELC",
        {4.0, 1.8, 1.5},
        1500.0,
        4,
        "electric",
        true
    );

    Vehicul* masinaNormala = new Masina(
        2,
        "B124GAS",
        {4.0, 1.8, 1.5},
        1400.0,
        4,
        "benzina",
        false
    );

    Vehicul* motocicleta = new Motocicleta(
        3,
        "B200MOTO",
        {2.5, 0.9, 1.2},
        300.0,
        600,
        false
    );

    Vehicul* camion = new Camion(
        4,
        "B999TRK",
        {8.0, 2.5, 3.5},
        9000.0,
        20000.0,
        4
    );

    std::cout << "\n===== TEST VEHICULE =====\n";
    std::cout << masinaElectrica->categorieVehicul()
              << " | electrica=" << masinaElectrica->esteElectric()
              << " | axe=" << masinaElectrica->obtineNumarAxe() << "\n";

    std::cout << motocicleta->categorieVehicul()
              << " | electrica=" << motocicleta->esteElectric()
              << " | axe=" << motocicleta->obtineNumarAxe() << "\n";

    std::cout << camion->categorieVehicul()
              << " | electrica=" << camion->esteElectric()
              << " | axe=" << camion->obtineNumarAxe() << "\n";

    // =========================
    // LOCURI DE PARCARE
    // =========================
    LocParcare locSimplu(10);
    LocParcareElectric locElectric(20, 1200.0, "Type2");
    LocParcareCamion locCamion(30, 30000.0, 4);

    std::cout << "\n===== TEST INCAPERE =====\n";

    std::cout << "Masina incape loc simplu: "
              << locSimplu.incapeVehicul(*masinaElectrica) << "\n";

    std::cout << "Camion incape loc simplu: "
              << locSimplu.incapeVehicul(*camion) << "\n";

    std::cout << "\n===== TEST ACCEPTARE =====\n";

    std::cout << "Masina electrica acceptata loc electric: "
              << locElectric.acceptaVehicul(*masinaElectrica) << "\n";

    std::cout << "Masina normala acceptata loc electric: "
              << locElectric.acceptaVehicul(*masinaNormala) << "\n";

    std::cout << "Camion acceptat loc electric: "
              << locElectric.acceptaVehicul(*camion) << "\n";

    std::cout << "Camion acceptat loc camion: "
              << locCamion.acceptaVehicul(*camion) << "\n";

    std::cout << "Masina acceptata loc camion: "
              << locCamion.acceptaVehicul(*masinaElectrica) << "\n";

    // =========================
    // TEST OCUPARE
    // =========================
    std::cout << "\n===== TEST OCUPARE =====\n";

    std::cout << "Loc simplu ocupat? "
              << locSimplu.esteOcupat() << "\n";

    locSimplu.ocupa();

    std::cout << "Loc simplu ocupat dupa ocupa()? "
              << locSimplu.esteOcupat() << "\n";

    locSimplu.elibereaza();

    std::cout << "Loc simplu ocupat dupa elibereaza()? "
              << locSimplu.esteOcupat() << "\n";

    // =========================
    // CLEANUP
    // =========================
    delete masinaElectrica;
    delete masinaNormala;
    delete motocicleta;
    delete camion;

    std::cout << "\n===== TEST FINALIZAT CU SUCCES =====\n";

    return 0;
}



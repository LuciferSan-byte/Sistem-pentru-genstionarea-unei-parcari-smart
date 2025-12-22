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
    // =====================
    // DIMENSIUNI
    // =====================
    Dimensiune dimMasina {4.0, 1.8, 1.5};
    Dimensiune dimCamion {8.0, 2.5, 3.5};

    Dimensiune dimLocMare {10.0, 3.0, 4.0};

    // =====================
    // VEHICULE
    // =====================
    Vehicul* masina = new Masina(
        1,
        "B111CAR",
        dimMasina,
        1400.0,
        4,
        "benzina",
        false
    );

    Vehicul* camion = new Camion(
        2,
        "B222TRK",
        dimCamion,
        9000.0,
        20000.0,
        3          // numar axe
    );

    Vehicul* motocicleta = new Motocicleta(
        3,
        "B333MOTO",
        dimMasina,
        300.0,
        600,
        false
    );

    // =====================
    // LOC PARCARE CAMION
    // =====================
    LocParcareCamion locCamion(1,
        dimLocMare,
	100,
        4      // numar axe permise
    );

    std::cout << "Masina acceptata in loc camion: "
              << locCamion.acceptaVehicul(*masina)
              << "\n";

    std::cout << "Motocicleta acceptata in loc camion: "
              << locCamion.acceptaVehicul(*motocicleta)
              << "\n";

    std::cout << "Camion acceptat in loc camion: "
              << locCamion.acceptaVehicul(*camion)
              << "\n";

    // =====================
    // CLEANUP
    // =====================
    delete masina;
    delete camion;
    delete motocicleta;

    return 0;
}



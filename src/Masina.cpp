#include "Masina.h"

Masina::Masina(int id,
    const std::string& numar,
    const Dimensiune& dim,
    double greutate,
    int numarUsi,
    const std::string& tipCombustibil,
    bool esteElectric
)
    : Vehicul(id, numar, dim, greutate),  
      numarUsi(numarUsi),
      tipCombustibil(tipCombustibil),
      esteElectric(esteElectric)
{
}

std::string Masina::categorieVehicul() const {
    return "Masina";
}

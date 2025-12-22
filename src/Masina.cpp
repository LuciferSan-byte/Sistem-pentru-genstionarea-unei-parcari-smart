#include "Masina.h"

Masina::Masina(int id,
    const std::string& numar,
    const Dimensiune& dim,
    double greutate,
    int numarUsi,
    const std::string& tipCombustibil,
    bool electrica
)
    : Vehicul(id, numar, dim, greutate),  
      numarUsi(numarUsi),
      tipCombustibil(tipCombustibil),
      electrica(electrica)
{
}

std::string Masina::categorieVehicul() const {
    return "Masina";
}

bool Masina::esteElectric()const{
    return electrica;
}
int Masina::obtineNumarAxe()const {return 2;}

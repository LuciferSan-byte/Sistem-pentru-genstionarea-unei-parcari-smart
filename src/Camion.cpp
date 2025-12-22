#include "Camion.h"

Camion::Camion(int id,
    const std::string& numar,
    const Dimensiune& dim,
    double greutate,
    double sarcinaMaxima,
    int numarAxe
    ) 
     : Vehicul(id, numar, dim, greutate),
       sarcinaMaxima(sarcinaMaxima),
       numarAxe(numarAxe)
{}

std::string Camion::categorieVehicul() const {
    return "Camion";
}
bool Camion::esteElectric()const {
    return false;
}
int Camion::obtineNumarAxe()const {return numarAxe;}

#include "Motocicleta.h"

Motocicleta::Motocicleta(int id,
    const std::string& numar,
    const Dimensiune & dim,
    double greutate,
    int capacitateMotor,
    bool areAtas
    ):Vehicul(id, numar, dim , greutate),
     capacitateMotor(capacitateMotor),
     areAtas(areAtas)
{}

std::string Motocicleta::categorieVehicul() const{
    return "Motocicleta";
}

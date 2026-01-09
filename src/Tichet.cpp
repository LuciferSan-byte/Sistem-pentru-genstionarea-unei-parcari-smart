#include "Tichet.h"

Tichet::Tichet(int id):
	idTichet(id),
	idLoc(-1),
	sumaDePlata(0.00),
	vehicul(nullptr),
	oraIntrare(std::chrono::system_clock::now()) {}

void Tichet::seteazaVehicul(Vehicul* v) {
    vehicul = v;
}

Vehicul* Tichet::obtineVehicul() const {
    return vehicul;
}

void Tichet::seteazaOraIesire(){
    oraIesire = std::chrono::system_clock::now();
}

void Tichet::inchide(){
    inchis = true;
}

bool Tichet::esteInchis()const{
    return inchis;
}

std::chrono::system_clock::time_point Tichet::obtineOraIntrare()const{
    return oraIntrare;
}

std::chrono::system_clock::time_point Tichet::obtineOraIesire()const{
    return oraIesire;
}

void Tichet::seteazaSuma(double suma){
    sumaDePlata = suma;
}

void Tichet::seteazaDurataMinute(int minute) {
    if(minute < 0) minute = 0;
    oraIesire = oraIntrare + std::chrono::minutes(minute);
}

int Tichet::obtineId() const{
    return idTichet;
}

double Tichet::obtineSuma()const{
    return sumaDePlata;
}

void Tichet::afiseazaSuma()const{
    std::cout << "Suma de Plata ";
    std::cout << std::fixed << std::setprecision(2) << sumaDePlata << " Lei";
}

void Tichet::seteazaIdLoc(int id) {
    idLoc = id;
}

int Tichet::obtineIdLoc() const {
    return idLoc;
}


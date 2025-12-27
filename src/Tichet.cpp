#include "Tichet.h"

Tichet::Tichet(int id):
	idTichet(id)
	{
	oraIntrare = std::chrono::system_clock::now();
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

double Tichet::obtineSuma()const{
    return sumaDePlata;
}

void Tichet::afiseazaSuma()const{
    std::cout << "Suma de Plata ";
    std::cout << std::fixed << std::setprecision(2) << sumaDePlata << " Lei";
}

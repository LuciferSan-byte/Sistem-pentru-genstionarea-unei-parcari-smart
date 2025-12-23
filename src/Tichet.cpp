#include "Tichet.h"

Tichet::Tichet(int id):
	idTichet(id)
	{
	oraIntrare = std::chrono::system_clock::now();
	}

void Tichet::seteazaOraIesire(){
    oreIesire = std::chrono:system_clock::now();
}

void Tichet::inchide(){
    inchis = true;
}
bool Tichet::esteInchis()const{
    return inchis;
}

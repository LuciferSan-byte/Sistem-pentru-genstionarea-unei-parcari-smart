#include "Sofer.h"

Sofer::Sofer(const int id, const std::string & nume, bool arePermisH):
	    idSofer(id),
	    nume(nume),
	    arePermisHandicap(arePermisH)
{
abonament = nullptr;
}

bool Sofer::arePermisH()const { return arePermisHandicap;}

bool Sofer::areAbonament()const{
    return abonament != nullptr;
}
Abonament* Sofer::obtineAbonament()const{
    return abonament;
}
void Sofer::seteazaAbonament(Abonament* abonamentNou){
    abonament = abonamentNou;
}
void Sofer::stergeAbonament(){
    abonament = nullptr;
}


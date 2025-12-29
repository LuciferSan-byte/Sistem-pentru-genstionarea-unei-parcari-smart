#include "LocParcare.h"
#include "Dimensiune.h"
LocParcare::LocParcare(int idLoc)
    : idLoc(idLoc), ocupat(false),vehiculAcceptat("Masina"), led()
{
    dimensiune = Dimensiune::pentruLocMasina();
}



bool LocParcare::incapeVehicul(const Vehicul &v)const{
    return v.obtineDimensiune().incapeIn(dimensiune);   
}

void LocParcare::ocupa(){
    ocupat = true;
    led.seteazaCuloarea(CuloareLed::Rosu);
}
void LocParcare::elibereaza(){
    ocupat = false;
    led.seteazaCuloarea(CuloareLed::Verde);
}
bool LocParcare::esteOcupat() const{
    return ocupat;
}

bool LocParcare::acceptaVehicul(const Vehicul &v)const{
    return v.categorieVehicul() == vehiculAcceptat;
}

void LocParcare::afiseazaStare() const{
    std::cout << "Loc " << idLoc << ": ";
    led.afiseaza();
}

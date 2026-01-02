#include "LocParcare.h"
#include "Dimensiune.h"
LocParcare::LocParcare(int idLoc)
    : idLoc(idLoc), ocupat(false),vehiculAcceptat("Masina"), led(), senzor(idLoc),electric(false) 
{
    dimensiune = Dimensiune::pentruLocMasina();
    handicap = false;
}

void LocParcare::detecteazaVehicul(){
    senzor.detecteaza();

    if(!ocupat){
	ocupa();
    }
}

void LocParcare::vehiculPleaca() {
    senzor.elibereaza();

    if(ocupat){
	elibereaza();
    }
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

bool LocParcare::esteElectric() const{
    return electric;
}

bool LocParcare::esteHandicap() const{
    return handicap;
}

std::string LocParcare::obtineVehiculAcceptat() const{
    return vehiculAcceptat;
}

Dimensiune LocParcare::obtineDimensiune() const {
    return dimensiune;
}

int LocParcare::obtineId() const { return idLoc;}

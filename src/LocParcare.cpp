#include "LocParcare.h"
#include "Dimensiune.h"
LocParcare::LocParcare(int idLoc)
    : idLoc(idLoc), ocupat(false),vehiculAcceptat("Masina"), led(), senzor(idLoc),electric(false) 
{
    dimensiune = Dimensiune::pentruLocMasina();
    handicap = false;
}

void LocParcare::detecteazaVehicul(){
    std::cout << "\nVehicul detectat pe locul cu id: " << obtineId() << "\n";
    senzor.detecteaza();
    if(!ocupat){
	ocupa();
    }
}

void LocParcare::vehiculPleaca() {
    std::cout << "\nVehiculul a parasit locul cu id: " << obtineId() << "\n";
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
    std::cout << "Led: {Verde} -> {Rosu}\n";
    led.seteazaCuloarea(CuloareLed::Rosu);
}
void LocParcare::elibereaza(){
    ocupat = false;
    std::cout << "Led: {Rosu} -> {Verde}\n";
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

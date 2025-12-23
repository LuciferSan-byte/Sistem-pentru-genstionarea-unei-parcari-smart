#include "LocParcare.h"
#include "Dimensiune.h"
LocParcare::LocParcare(int idLoc)
    : idLoc(idLoc), ocupat(false),vehiculAcceptat("Masina")
{
    dimensiune = Dimensiune::pentruLocMasina();
}



bool LocParcare::incapeVehicul(const Vehicul &v)const{
    return v.obtineDimensiune().incapeIn(dimensiune);   
}

void LocParcare::ocupa(){
    ocupat = true;
}
void LocParcare::elibereaza(){
    ocupat = false;
}
bool LocParcare::esteOcupat() const{
    return ocupat;
}

bool LocParcare::acceptaVehicul(const Vehicul &v)const{
    return v.categorieVehicul() == vehiculAcceptat;
}

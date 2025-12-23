#include "LocParcareCamion.h"

LocParcareCamion::LocParcareCamion(int id,double sarcinaMaxima,int numarAxePermise):
	    LocParcare(id),
	    sarcinaMaxima(sarcinaMaxima),
	    numarAxePermise(numarAxePermise)
	    {
	    dimensiune = Dimensiune::pentruLocCamion();
	    vehiculAcceptat = "Camion";} 

bool LocParcareCamion::acceptaVehicul(const Vehicul& v) const {
    if(v.categorieVehicul() != vehiculAcceptat){
	std::cout << "Pe acest loc de parcare sunt permise doar camioane\n";
	return false;
    }
    if(v.obtineNumarAxe() > numarAxePermise){
	std::cout << "Numarul de axe este prea mare\n";
	return false;
    }
    return true;
}
	    

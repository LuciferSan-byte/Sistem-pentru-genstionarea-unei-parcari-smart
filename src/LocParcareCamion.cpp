#include "LocParcareCamion.h"

LocParcareCamion::LocParcareCamion(int id, const Dimensiune &dim,double sarcinaMaxima,int numarAxePermise):
	    LocParcare(id,dim),
	    sarcinaMaxima(sarcinaMaxima),
	    numarAxePermise(numarAxePermise){vehiculAcceptat = "Camion";} 

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
	    

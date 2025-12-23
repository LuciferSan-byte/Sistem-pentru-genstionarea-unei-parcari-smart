#include "LocParcareMotocicleta.h"
#include <iostream>
LocParcareMotocicleta::LocParcareMotocicleta(int idLoc, int numarMaximMotociclete):
	    LocParcare(idLoc),
	    numarMaximMotociclete(numarMaximMotociclete)
	    {dimensiune = Dimensiune::pentruLocMoto();
	     vehiculAcceptat = "Motocicleta";}
		    
bool LocParcareMotocicleta::acceptaVehicul(const Vehicul& v) const{
    if(v.categorieVehicul() != vehiculAcceptat){
	std::cout << "Acest loc este pentru Motocicleta\n";
	return false;
    }
    return true;
}

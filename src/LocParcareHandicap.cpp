#include "LocParcareHandicap.h"

LocParcareHandicap::LocParcareHandicap(int id,double latimeZonaAcces,bool aproapeIntrare, bool electric):
		    LocParcare(id),
		    latimeZonaAcces(latimeZonaAcces),
		    aproapeIntrare(aproapeIntrare) 
		    {dimensiune = Dimensiune::pentruLocMasina();
		     vehiculAcceptat = "Masina";
		     this->electric = electric;
		     handicap = true;
		    }

bool LocParcareHandicap::acceptaVehicul(const Vehicul &v)const{
    return v.categorieVehicul() != vehiculAcceptat;
}

bool LocParcareHandicap::acceptaSofer(const Sofer& s)const{
    return s.arePermisH();
}

bool LocParcareHandicap::esteAccesibil()const{
    return aproapeIntrare;
}


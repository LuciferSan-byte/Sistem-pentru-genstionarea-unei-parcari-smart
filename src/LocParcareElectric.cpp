#include "LocParcareElectric.h"
#include "Dimensiune.h"

LocParcareElectric::LocParcareElectric(int id, double putere,const std::string &conector)
		    :LocParcare(id),
		    putereIncarcare(putere),
		    tipConector(conector) 
{dimensiune = Dimensiune::pentruLocMasina();
 electric = true;
}

bool LocParcareElectric::acceptaVehicul(const Vehicul& v)const{
    return v.categorieVehicul() == vehiculAcceptat && v.esteElectric() == true;
}


#include "LocParcareElectric.h"
#include "Dimensiune.h"

LocParcareElectric::LocParcareElectric(int id, const Dimensiune& dim, double putere,const std::string &conector)
		    :LocParcare(id,dim),
		    putereIncarcare(putere),
		    tipConector(conector) 
{}

bool LocParcareElectric::acceptaVehicul(const Vehicul& v)const{
    return v.categorieVehicul() == vehiculAcceptat && v.esteElectric() == true;
}


#include "Dimensiune.h"

bool Dimensiune::incapeIn(const Dimensiune& alta) const{
    return lungime <= alta.lungime &&
	    latime <= alta.latime &&
	    inaltime <= alta.inaltime;
}

Dimensiune Dimensiune::pentruLocMasina(){return {5.0, 2.0, 2.0};}

Dimensiune Dimensiune::pentruLocCamion(){return {10.0, 3.0, 4.0};}

Dimensiune Dimensiune::pentruLocMoto(){return {3.0, 1.2, 1.5};}

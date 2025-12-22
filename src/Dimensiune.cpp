#include "Dimensiune.h"

bool Dimensiune::incapeIn(const Dimensiune& alta) const{
    return lungime <= alta.lungime &&
	    latime <= alta.latime &&
	    inaltime <= alta.inaltime;
}

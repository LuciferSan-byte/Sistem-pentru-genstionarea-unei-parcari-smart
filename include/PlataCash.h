#pragma once 
#include "MetodaPlata.h"

class PlataCash : public MetodaPlata{
public:
    bool efectueazaPlata(double suma) const override;
};
    

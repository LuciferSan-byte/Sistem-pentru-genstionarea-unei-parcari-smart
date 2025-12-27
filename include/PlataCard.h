#pragma once

#include "MetodaPlata.h"

class PlataCard : public MetodaPlata{
public:
    bool efectueazaPlata(double suma)const override;
};

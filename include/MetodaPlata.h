#pragma once

class MetodaPlata{
public:
    virtual bool efectueazaPlata(double suma)const = 0;
    virtual ~MetodaPlata() = default;
};

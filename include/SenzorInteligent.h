#pragma once

#include <string>
#include "Camera.h"
#include "Senzor.h"
#include "Vehicul.h"

class SenzorInteligent : public Camera, public Senzor {
private:
    std::string ultimulNumarDetectat;

public:
   explicit SenzorInteligent(int id);

    bool proceseazaVehicul(const Vehicul &v);

    std::string obtineUltimulNumar() const;
};


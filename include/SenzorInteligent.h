#pragma once

#include <string>
#include "Camera.h"
#include "Senzor.h"

class SenzorInteligent : public Camera, public Senzor {
private:
    std::string locatie;

public:
    SenzorInteligent(int id, const std::string& locatie);

    bool detecteazaPrezenta() const override;
    std::string captureazaImagine() const override;
    std::string recunoasteNumar() const override;
};


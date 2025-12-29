#pragma once

#include <string>
#include <iostream>

enum class CuloareLed{
    Verde,
    Rosu,
};

class Led{
private:
    CuloareLed culoare;

public:
    
    Led();
    void seteazaCuloarea(CuloareLed culoareNoua);
    CuloareLed obtineCuloare() const;
    void afiseaza() const;
};

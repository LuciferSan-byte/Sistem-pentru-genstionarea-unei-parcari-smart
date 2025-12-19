#pragma once

#include <ctime>

class Tichet {
private:
    const int idTichet;
    std::time_t oraIntrare;
    std::time_t oraIesire;
    double sumaDePlata;
    bool inchis;

public:
    Tichet(int id);

    void seteazaOraIesire(std::time_t t);
    void seteazaSuma(double suma);
    void inchide();

    bool esteInchis() const;
};


#pragma once

#include <ctime>
#include <chrono>
#include <iostream>

class Tichet {
private:
    const int idTichet;
    std::chrono::system_clock::time_point oraIntrare;
    std::chrono::system_clock::time_point oraIesire;
    double sumaDePlata;
    bool inchis;

public:
    Tichet(int id);

    void seteazaOraIesire();
    void seteazaSuma(double suma);
    void inchide();
 
    bool esteInchis() const;
};


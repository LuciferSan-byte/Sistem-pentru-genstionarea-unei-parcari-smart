#pragma once

#include <ctime>
#include <chrono>
#include <iostream>
#include "Vehicul.h"

class Tichet {
private:
    int idTichet;
    Vehicul* vehicul;
    int idLoc;

    std::chrono::system_clock::time_point oraIntrare;
    std::chrono::system_clock::time_point oraIesire;
    double sumaDePlata;
    bool inchis{false};

public:
    explicit Tichet(int id);

    void seteazaVehicul(Vehicul* v);
    Vehicul* obtineVehicul() const;

    void seteazaOraIesire();
    void seteazaSuma(double suma);
    void inchide();
    
    int obtineId() const;
    
    void seteazaDurataMinute(int minute);

    void afiseazaSuma()const;
    double obtineSuma()const;
    
    void seteazaIdLoc(int id);
    int obtineIdLoc() const;

    std::chrono::system_clock::time_point  obtineOraIntrare() const;
    std::chrono::system_clock::time_point  obtineOraIesire() const;
    


    bool esteInchis() const;
};


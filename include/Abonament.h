#pragma once

#include <string>
#include <ctime>
#include <chrono>
#include <iostream>

class Abonament {
private:
    const int idAbonament;
    std::string tip;
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point expire;

public:
    Abonament(const int &id,
	      std::string tipul);

    bool esteValid() const;
    
    void reinoiesteAbonamentLunar();
    void reinoiesteAbonamentAnual();


    std::chrono::system_clock::time_point obtineStart()const;
    std::chrono::system_clock::time_point obtineExpire()const;

    void afiseazaInceputAbonament()const;
    void afiseazaExpirareAbonament()const;
    std::string obtineTip() const;
};


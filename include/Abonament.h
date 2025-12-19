#pragma once

#include <string>
#include <ctime>

class Abonament {
private:
    const int idAbonament;
    std::string tip;
    std::time_t validPanaLa;

public:
    Abonament(int id,
              const std::string& tip,
              std::time_t validPanaLa);

    bool esteValid() const;
    std::string obtineTip() const;
};


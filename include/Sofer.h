#pragma once

#include <string>

class Abonament;

class Sofer {
private:
    const int idSofer;
    std::string nume;
    bool arePermisHandicap;
    Abonament* abonament;

public:
    Sofer(int id, const std::string& nume, bool arePermisHandicap);

    bool arePermis() const;
    bool areAbonament() const;
    Abonament* obtineAbonament() const;

    void seteazaAbonament(Abonament* abonament);
};


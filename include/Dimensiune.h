#pragma once 

struct Dimensiune {
    double lungime;
    double latime;
    double inaltime;

    bool incapeIn(const Dimensiune & alta) const;
};

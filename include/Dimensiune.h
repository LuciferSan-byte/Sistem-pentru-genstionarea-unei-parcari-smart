#pragma once 

struct Dimensiune {
    double lungime;
    double latime;
    double inaltime;

    bool incapeIn(const Dimensiune & alta) const;
    static Dimensiune pentruLocMasina();
    static Dimensiune pentruLocCamion();
    static Dimensiune pentruLocMoto();
};

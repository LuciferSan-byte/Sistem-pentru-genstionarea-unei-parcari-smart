#pragma once

class Tichet;
class Vehicul;

class PoliticaPret {
public:
    virtual ~PoliticaPret() = default;
    virtual double calculeazaPret(const Tichet& t,
                                  const Vehicul& v) const = 0;
};


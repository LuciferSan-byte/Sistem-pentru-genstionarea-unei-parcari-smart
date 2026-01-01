#pragma once

class Senzor {
protected:
    const int idSenzor;
    bool vehiculDetectat;
public:
    Senzor(int id);
    virtual ~Senzor() = default;
    virtual void detecteaza();
    virtual void elibereaza() ;

    bool esteActiv() const; 
};


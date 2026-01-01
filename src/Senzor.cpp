#include "Senzor.h"

Senzor::Senzor(int id) : idSenzor(id), vehiculDetectat(false){}

void Senzor::detecteaza(){
    vehiculDetectat = true;
}

void Senzor::elibereaza(){
    vehiculDetectat = false;
}

bool Senzor::esteActiv() const{
    return vehiculDetectat;
}

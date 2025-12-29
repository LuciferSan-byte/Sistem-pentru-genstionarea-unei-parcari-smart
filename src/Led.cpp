#include "Led.h"

Led::Led() : culoare(CuloareLed::Verde){}

void Led::seteazaCuloarea(CuloareLed culoareNoua){
    culoare = culoareNoua;
}

CuloareLed Led::obtineCuloare() const{
    return culoare;
}

void Led::afiseaza() const{
    if (culoare == CuloareLed::Verde)
	std::cout << "[LED] 🟢 LIBER\n";
    else 
	std::cout << "[LED] 🔴 OCUPAT\n";
}



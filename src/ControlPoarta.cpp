#include "ControlPoarta.h"

ControlPoarta::ControlPoarta() : deschisa(false) {}

bool ControlPoarta::esteDeschisa() const { return deschisa;}

void ControlPoarta::deschide() {
    if (deschisa) {
	std::cout << "Poarta este deja deschisa \n";
	return;
    }
    
    
    std::cout << "Se deschide Poarta";
    for (int i = 0; i < 3; ++i) {
        std::cout << "." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    deschisa = true;
    std::cout << "\nPoarta DESCHISA\n";
}

void ControlPoarta::inchide(){
        if (!deschisa) {
        std::cout << "Poarta este deja inchisa.\n";
        return;
    }

    std::cout << "Se inchide Poarta";
    for (int i = 0; i < 3; ++i) {
        std::cout << "." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    deschisa = false;
    std::cout << "\nPoarta INCHISA \n";
}

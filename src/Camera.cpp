#include "Camera.h"
#include <limits>

bool Camera::captureazaImagine() const{
    std::cout << "Camera: se asteapta un vehicul...\n";
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Apasa ENTER pentru a simula trecerea vehiculului.\n";
    std::cin.get(); 

    for (int i = 0; i <= 10; i++) {
        std::cout << "\r";             

        for (int j = 0; j < i; j++) {
            std::cout << "=";
        }

        std::cout << ">" << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << "\nVehciul detectat!\n";
    return true;
}

std::string Camera::recunoasteNumar(const Vehicul & v)const{
    
    std::cout << "Camera: Se incearca recunoasterea numarului\n";
    
    for (int i = 0; i < 3; i++){
	std::cout << "\r";

	for (int j = 0; j < 5; j++){
	    std::cout << "." << std::flush;
	    std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
	std::cout << "\033[2K\r";
    }

    std::cout << "\nNumarul a fost recunoscut cu succes\n";
    std::cout << "Numarul recunoscut: " << v.obtineNumarInmatriculare() << "\n";
    return v.obtineNumarInmatriculare();

}

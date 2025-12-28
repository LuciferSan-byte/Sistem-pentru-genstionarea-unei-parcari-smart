#include "PlataCash.h"
#include <vector>
#include <limits>
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <string>

void fnct_pol_cv();

std::vector<int> bancnote = {1 , 5 , 10 , 20 , 50, 100 , 200 , 500};

bool PlataCash::efectueazaPlata(double suma) const{
    int cnt = 0;    
    double sumaPlatita = 0, alegere;
   
    while (sumaPlatita < suma){
	std::cout << "\033[2J\033[H"; // clear screen cross platform
	std::cout << "Suma de Achitat: " << suma << "Lei\n";
	std::cout << "Suma introdusa: " << sumaPlatita << "Lei\n\n";

	std::cout << "Introdu bancnote\n";
	for(int i = 0 ; i < bancnote.size();i++)
	    std::cout << "[" << i + 1 << "]" << " " << bancnote[i] << "\n";
	
	std::string line;
	std::cout << ">";
	std::getline(std::cin,line);
	
	std::stringstream ss(line);
	
	if(!(ss >> alegere)){
	
	    std::cout << "\nAi introdus bancnote false\n" << std::endl;
	    cnt++;
	    std::this_thread::sleep_for(std::chrono::seconds(3));
	    if(cnt == 10){
		fnct_pol_cv();
		break;
	    }
	    continue;
	}

	if(alegere < 1 || alegere > static_cast<int>(bancnote.size())){
	    std::cout << "Ai introdus bancnote neexistente\n";
	    std::this_thread::sleep_for(std::chrono::seconds(3));
	    continue;
	}
	std::cout << "Bancnota introdusa cu succes\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	sumaPlatita += bancnote[alegere - 1];
    }
    std::cout << "Suma a fost achitata in intregime\n";
    std::cout << "Rest: " << sumaPlatita - suma << "Lei\n";
    
    return true;
}

void fnct_pol_cv(){
   using clock = std::chrono::steady_clock;

    auto start = clock::now();
    bool toggle = false;

    std::cout << "Politia a fost anuntata!\n";
    while (clock::now() - start < std::chrono::seconds(10)) {
        if (toggle) {
        std::cout
            << "\033[1;31m==========\033[0m"
            << "||"
            << "\033[1;34m==========\033[0m"
            << "\r" << std::flush;
    } else {
        std::cout
            << "\033[1;34m==========\033[0m"
            << "||"
            << "\033[1;31m==========\033[0m"
            << "\r" << std::flush;
    }
        toggle = !toggle;

        std::this_thread::sleep_for(std::chrono::milliseconds(120)); 
    } 
    exit(1);
}





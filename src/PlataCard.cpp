#include "PlataCard.h"
#include <chrono>
#include <thread>
#include <random>
#include <iostream>
#include <vector>
#include <thread>

enum class EroarePlata{
    FonduriInsuficiente,
    CardExpirat,
    CardBlocat,
    EroareRetea,
    TerminalIndisponibil
};

std::vector<EroarePlata> eroriPosibile = {
    EroarePlata::FonduriInsuficiente,
    EroarePlata::CardExpirat,
    EroarePlata::CardBlocat,
    EroarePlata::EroareRetea,
    EroarePlata::TerminalIndisponibil
};

std::string mesajEroare(EroarePlata eroare) {
    switch (eroare) {
        case EroarePlata::FonduriInsuficiente:
            return "Fonduri insuficiente";
        case EroarePlata::CardExpirat:
            return "Card expirat";
        case EroarePlata::CardBlocat:
            return "Card blocat";
        case EroarePlata::EroareRetea:
            return "Eroare de retea";
        case EroarePlata::TerminalIndisponibil:
            return "Terminal indisponibil";
        default:
            return "Eroare necunoscuta";
    }
}

bool PlataCard::efectueazaPlata(double suma)const{
    std::cout << "\nTranzactia se proceseaza";
    for(int i = 0; i  < 3; i++){
	std::cout << "." << std::flush;
	std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
    // generator numere random
    std::random_device rd;  // sursa de entropie
    std::mt19937 gen(rd()); // generator Mersenne Twister
    std::uniform_int_distribution<int> dist(1,100);
    std::uniform_int_distribution<int> dist1(0, eroriPosibile.size() - 1);

    int x = dist(gen);
    int y = dist(gen);

    if(1 != 1){
	std::cout << "\nTranzactie Aprobata\n";
	return true;
    }
    std::cout << "\nTranzactie Respinsa\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    EroarePlata eroareAlesa = eroriPosibile[dist1(gen)];
    std::cout << mesajEroare(eroareAlesa) << std::endl;

    return false;
}



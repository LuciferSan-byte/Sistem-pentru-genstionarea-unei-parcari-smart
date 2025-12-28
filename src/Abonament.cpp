#include "Abonament.h"

Abonament::Abonament(const int &id,std::string tipul):
		    idAbonament(id),
		    tip(tipul),
		    esteActiv(false)
{
}

void Abonament::incepereAbonament()
{
     start = std::chrono::system_clock::now();
     expire = start + std::chrono::days{30};

    std::cout << "---Abonament activat cu succes---";

    this->afiseazaInceputAbonament();
    this->afiseazaExpirareAbonament();
}
bool Abonament::esteActv()const {
    return esteActiv;
}
bool Abonament::esteValid()const {
    return std::chrono::system_clock::now() < expire;
}
void Abonament::reinoiesteAbonamentLunar() {
    expire += std::chrono::days{30};
}
void Abonament::reinoiesteAbonamentAnual() {
    expire += std::chrono::days{365};
}

std::string Abonament::obtineTip()const {
    return tip;
}

std::chrono::system_clock::time_point Abonament::obtineStart()const {
    return start;
}

std::chrono::system_clock::time_point Abonament::obtineExpire()const {
    return expire;
}

void Abonament::afiseazaInceputAbonament()const {
    std::time_t t = std::chrono::system_clock::to_time_t(start);
    if(!t){
	std::cerr << "\nNu exista Abonamnet activ\n";
	return;
    }

    std::cout << "\nAbonamentul a fost activat pe data de : ";
    std::cout << std::ctime(&t);
}
void Abonament::afiseazaExpirareAbonament()const {
    std::time_t t = std::chrono::system_clock::to_time_t(expire);
    if(!t){
	std::cerr << "\nNu exista Abonamnet activ\n";
	return;
    }

    std::cout << "Abonamentul este valid pana pe data de : ";
    std::cout << std::ctime(&t);
}

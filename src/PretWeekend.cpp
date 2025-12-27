#include "PretWeekend.h"

PretWeekend::PretWeekend():tarifOra(3){}

double PretWeekend::calculeazaPret(const Tichet &t )const{
    double minute = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<3600>>>(t.obtineOraIesire()-t.obtineOraIntrare()).count();
    return minute*tarifOra;
}

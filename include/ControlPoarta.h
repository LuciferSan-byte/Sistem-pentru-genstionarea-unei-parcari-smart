#pragma once

#include <iostream>
#include <thread>
#include <chrono>

class ControlPoarta{
private:
    bool deschisa;
public:
    ControlPoarta();

    bool esteDeschisa() const;

    void deschide();
    void inchide();
};

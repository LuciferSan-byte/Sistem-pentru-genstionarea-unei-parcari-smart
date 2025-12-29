#pragma once

#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include "Vehicul.h"
#include <random>

class Camera {
public:
    virtual ~Camera() = default;

    virtual bool captureazaImagine() const;
    virtual std::string recunoasteNumar(const Vehicul & v) const;
};


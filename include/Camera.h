#pragma once

#include <string>

class Camera {
public:
    virtual ~Camera() = default;

    virtual std::string captureazaImagine() const;
    virtual std::string recunoasteNumar() const;
};


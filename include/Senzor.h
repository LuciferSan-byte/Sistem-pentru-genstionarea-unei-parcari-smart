#pragma once

class Senzor {
protected:
    const int idSenzor;
    bool stare;

public:
    Senzor(int id);
    virtual ~Senzor() = default;

    virtual bool detecteazaPrezenta() const;
    virtual void reseteaza();
};


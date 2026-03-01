#ifndef PKW_H
#define PKW_H

#include "fahrzeug.h"

class PKW : public Fahrzeug
{
public:
    PKW();

    void accelerate() override; //Methode aus Elternklasse wurde überschrieben
    void showSpeed() const override;
    void showValues();
};

#endif // PKW_H

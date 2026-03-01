#ifndef BOOT_H
#define BOOT_H

#include "fahrzeug.h"

class Boot : virtual public Fahrzeug //wissen, dass bei gleichen elementen nur einmal vorhanden
{
public:
    Boot();

    virtual void accelerate() override;

    void showStatus() const;
};

#endif // BOOT_H

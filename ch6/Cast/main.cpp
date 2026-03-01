#include <iostream>

#include "pkw.h"

int main()
{   //PKW erzeugt, gespeichert im Zeiger der Fahrzeugklasse
    Fahrzeug *fzeug = new PKW;
    //Zeiger wird gewandelt (runter gewandelt)
    auto *cabrio = dynamic_cast<PKW*>(fzeug); // From Base -> Derived
                                //soll werden
    if(cabrio) // nullptr set if dynamic_cast failed
    {
        cabrio->accelerate();
        cabrio->showValues();
    }
    //Zeiger wird hoch gewandelt, auch für float, int,...
    Fahrzeug *upwardCast = static_cast<PKW*>(cabrio); // From Derived -> Base. Also good for primitive types (v.g. float to int)
                                        //war zuvor
    upwardCast->showSpeed();

    void *dirtyCast = reinterpret_cast<void*>(fzeug); //alle Infos verloren

    const auto *immutableCar = const_cast<const PKW*>(cabrio); // For setting or removing const

    immutableCar->showSpeed(); // OK
    //immutableCar->accelerate(); // ERROR

    // Classical casts
    auto x = float(2); // Function style cast

    auto y = (float)(2); // C-Style cast

    delete fzeug;

    return 0;
}

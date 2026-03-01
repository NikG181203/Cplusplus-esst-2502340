// C++ implementation​​​​​​‌‌‌‌​​​‌‌‌​​​​‌​​‌‌‌‌‌​​​ below
//////////////////////////////////////////////////////////
/// Header Dateien
#define showExpectedResult
#define showHints
//////////////////////////////////////////////////////////
// ----------- fahrzeug.h -------------
#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <iostream>

class Fahrzeug
{
public:
    Fahrzeug();

    // TODO: Virtualize accelerate as pure method
    virtual void accelerate(const float seconds) = 0;

    void showValues() const;

    float getSpeed() const;

    void setSpeed(float newSpeed);

private:
    float mSpeed = 0.0f; // km/h
};

#endif // FAHRZEUG_H


// ----------- pkw.h -------------
#ifndef PKW_H
#define PKW_H

class PKW : public Fahrzeug
{
public:
    PKW();

    void drive(const float seconds);

    void showValues() const;

    float getPosition() const;
    void setPosition(float newPosition);

private:
    float mPosition = 0.0f; // km

};

#endif // PKW_H

// ----------- electriccar.h -------------
#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

class ElectricCar : public PKW
{
public:

    void accelerate(const float seconds) override;

    ElectricCar();

private:

    const float mAcceleration = 20000.0f; // km/(h^2)
};

#endif // ELECTRICCAR_H

// ----------- dieselcar.h -------------
#ifndef DIESELCAR_H
#define DIESELCAR_H

class DieselCar : public PKW
{
public:

    // TODO: accelerate methode implementieren die overwrite nutzt
    void accelerate(const float seconds) override;

    DieselCar();

private:

    const float mAcceleration = 10000.0f; // km/(h^2)
};

#endif // DIESELCAR_H

//////////////////////////////////////////////////////////
/// CPP-Dateien
//////////////////////////////////////////////////////////
// ----------- fahrzeug.cpp -------------
Fahrzeug::Fahrzeug() {}

void Fahrzeug::showValues() const
{
    // TODO: Geschwindigkeit ausgeben reicht
    std::cout << "Geschwindigkeit: " << getSpeed() << std::endl;
}

float Fahrzeug::getSpeed() const
{
    return mSpeed;
}

void Fahrzeug::setSpeed(float newSpeed)
{
    mSpeed = newSpeed;
}

// ----------- pkw.cpp -------------

PKW::PKW() {}

void PKW::drive(const float seconds)
{
    mPosition += (seconds*getSpeed())/3600;
}

void PKW::showValues() const
{
    Fahrzeug::showValues();
    std::cout << "Pos is " << mPosition*1000 << " m." << std::endl;
}

float PKW::getPosition() const
{
    return mPosition;
}

void PKW::setPosition(float newPosition)
{
    mPosition = newPosition;
}

// ----------- electriccar.cpp -------------
ElectricCar::ElectricCar() {}

void ElectricCar::accelerate(const float seconds)
{
    const auto pos = getPosition();
    const auto boost = 0.5f*(mAcceleration*seconds*seconds/(3600*3600));
    setPosition(pos + boost);
    setSpeed(getSpeed() + mAcceleration*(seconds/3600));
}

// ----------- dieselcar.cpp -------------
DieselCar::DieselCar() {}

void DieselCar::accelerate(const float seconds)
{
    // TODO: Hier eine Formel aufstellen, die Geschwindigkeit und hinterlegte Strecke berechnet
    const auto pos = getPosition();
    const auto boost = 0.5f*(mAcceleration*seconds*seconds/(3600*3600));
    setPosition(pos + boost);
    setSpeed(getSpeed() + mAcceleration*(seconds/3600));
}





// --------- main.cpp -----------------
// So wird Ihr Code aufgerufen.
// Für eigene Tests können Sie gerne weiteren Code hinzufügen.
// Achten Sie aber darauf, dass der Prozess inkl. Zahlen gleich bleibt.
// Bitte auch die Objekte p308 und tesla nicht umbenennen.

DieselCar p308;
ElectricCar tesla;

// Accelerate for one second
// Assume that while accelerating the position is kept the same.
// (like car is not touching surface while getting sped up)
p308.accelerate(10.0);
tesla.accelerate(10.0);

// Show me how fast and far you are.
std::cout << "How fast are the cars now?" << std::endl;
std::cout << "p308:" << std::endl;
p308.showValues();
std::cout << "tesla:" << std::endl;
tesla.showValues();

// Drive a bit
// Now the position changes.
// (Car touches the surface)
p308.drive(10.0);
tesla.drive(10.0);

// Show me how fast and far you are.
std::cout << "How fast are the cars after driving a bit?" << std::endl;
std::cout << "p308:" << std::endl;
p308.showValues();
std::cout << "tesla:" << std::endl;
tesla.showValues();


#ifndef FAHRZEUG_H
#define FAHRZEUG_H

// Interface Class
class Fahrzeug
{
public:
    Fahrzeug();
    virtual ~Fahrzeug() {};

    virtual void showSpeed() const; //kann von avgeleiteter Klasse üebrschrieben werden

    virtual void accelerate() = 0; //= 0 hat keine Implementierung

    float getPos() { return mPosition; }

protected:
    float mSpeed = 0.0f;

private:
    float mPosition = 0.0f;
};

#endif // FAHRZEUG_H

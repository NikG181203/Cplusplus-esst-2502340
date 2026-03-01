#include "customer.h"

Customer::Customer() : //zweiter Konstruktor, greift wenn erster nicht gegeben
mName("Unknown")
{}

Customer::Customer(const std::string &name) : //alternative zu Klammern, mit doppelpunkt hat höhere prio
mName(name) //Initialisierungsliste -> expliziter Konstruktor verlangt Name

std::string Customer::getName()
{
    return mName;
}

void Customer::rename(const std::string &name)
{
    mName = name;
}


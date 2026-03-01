#include "customer.h"
#include <iostream>

Customer::Customer(const std::string &name) :
mName(name)
{}

Customer::~Customer()
{
    std::cout << "Customer wird zerstört." << std::endl;
}

std::string Customer::getName()
{
    return mName;
}

void Customer::rename(const std::string &name)
{
    mName = name;
}

void askForName(Customer &person) //Zugriff über Public, da nicht in Klasse enthalten
{
    std::cout << person.getName() << std::endl;
}
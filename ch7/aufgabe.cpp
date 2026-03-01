// C++ implementation​​​​​​‌‌‌‌​​‌​​​‌​‌​​​‌​‌​‌​​​​ below
////////////////////////
// Header Dateien
////////////////////////

// zookeeper.h
#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H


class Zookeeper
{
public:
    Zookeeper();

    void removeFood(const int amnt);

    void printResources();

private:
    int mBagsOfFood = 100;
};

#endif // ZOOKEEPER_H


// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <memory>

class Animal
{
public:
    Animal();

    virtual void catchFoodFrom(std::unique_ptr<Zookeeper> &&zk) = 0;

    std::unique_ptr<Zookeeper> && releaseZooKeeper();

protected:
    std::unique_ptr<Zookeeper> mCurZookeeper;
};


class Elefant : public Animal
{
public:
    // TODO: Add definition for catchFoodFrom that overrides the virtual method of Animal
    void catchFoodFrom(std::unique_ptr<Zookeeper> &&zk) override;

};

class Giraffe : public Animal
{
public:
    // TODO: Add definition for catchFoodFrom that overrides the virtual method of Animal
    void catchFoodFrom(std::unique_ptr<Zookeeper> &&zk) override;
};

class Lion : public Animal
{
public:
    // TODO: Add definition for catchFoodFrom that overrides the virtual method of Animal
    void catchFoodFrom(std::unique_ptr<Zookeeper> &&zk) override;
};


#endif // ANIMAL_H

////////////////////////
// Cpp Dateien
////////////////////////
// zookeeper.cpp
#include <iostream>

Zookeeper::Zookeeper()
{}

void Zookeeper::removeFood(const int amnt)
{
    mBagsOfFood -= amnt;
}

void Zookeeper::printResources()
{
    std::cout << "Bags of Food: " << mBagsOfFood << std::endl;
}

// animal.cpp
Animal::Animal()
{}

std::unique_ptr<Zookeeper> && Animal::releaseZooKeeper()
{
    // TODO: Code for moving the zookeeper instance
    return std::move(mCurZookeeper);
}

// TODO: Put the catchFoodFrom Methods of Elefant, Giraffe and Lion here
void Elefant::catchFoodFrom(std::unique_ptr<Zookeeper> &&zk){
    mCurZookeeper = std::move(zk); //funktioniert wegen &&         //mein Pointer holt sich Instanz von Pointer, der auf Zookeper zeigt
    mCurZookeeper->removeFood(20);
}

void Giraffe::catchFoodFrom(std::unique_ptr<Zookeeper> &&zk){
    mCurZookeeper = std::move(zk);
    mCurZookeeper->removeFood(15);
}

void Lion::catchFoodFrom(std::unique_ptr<Zookeeper> &&zk){
    mCurZookeeper = std::move(zk);
    mCurZookeeper->removeFood(10);
}






// --------- main.cpp -----------------
// So wird Ihr Code aufgerufen.
// Für eigene Tests können Sie gerne weiteren Code hinzufügen.
// Achten Sie aber darauf, dass die Variable-Namen 
// elefant, giraffe, lion und zookeeper gleich bleiben.
auto elefant = std::make_unique<Elefant>();
auto giraffe = std::make_unique<Giraffe>();
auto lion = std::make_unique<Lion>();

auto zookeeper = std::make_unique<Zookeeper>();

std::cout << "Zookeeper feeding the elefant." << std::endl;
elefant->catchFoodFrom( std::move(zookeeper) );

if(!zookeeper)
{
    std::cout << "Zookeeper is busy feeding one animal." << std::endl;
}

zookeeper = elefant->releaseZooKeeper();

if(zookeeper)
{
    std::cout << "Zookeeper is ready to feed another animal." << std::endl;
}

zookeeper->printResources();

std::cout << "Zookeeper feeding the giraffe." << std::endl;
giraffe->catchFoodFrom( std::move(zookeeper) );
zookeeper = giraffe->releaseZooKeeper();

zookeeper->printResources();

std::cout << "Zookeeper feeding the lion." << std::endl;
lion->catchFoodFrom( std::move(zookeeper) );
zookeeper = lion->releaseZooKeeper();

std::cout << "Zookeeper fed every animal." << std::endl;
zookeeper->printResources();




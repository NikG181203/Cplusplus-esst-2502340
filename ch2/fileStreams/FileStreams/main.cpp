#include <iostream>
#include <fstream> //file stream
#include <array> //c++ array

int main()
{

    std::ofstream file("myFile.txt"); //file erstellen + öffnen

    std::array<int, 3> x = {10, 20, 30}; //array definition

    file << x[0] << std::endl; //je eine Zeile in file
    file << x[1] << std::endl;
    file << x[2] << std::endl;
    file.close(); //datei schließen

    x.fill(0);

    for(const auto &e : x) { //für jedes Element in Array tue folgendes
        std::cout << e << std::endl;
    }

    std::ifstream readFile("myFile.txt"); //file lesen

    if(!readFile) { //wenn nicht existiert
        std::cerr << "Fehler: Datei ist nicht lesbar!"; //cerr funkioniert schneller als cout
        return 1;
    }

    readFile >> x[0]; //werte aus file in array schreiben
    readFile >> x[1];
    readFile >> x[2];
    readFile.close();

    for(const auto &e : x) {
        std::cout << e << std::endl;
    }

    return 0;
}


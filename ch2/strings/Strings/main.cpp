#include <iostream>
#include <string>

int main()
{
    std::string myText; //Variable als Text String definiert

    std::cout << myText; // Leerer String

    myText = "Hello";
    std::cout << myText << std::endl;

    myText += "World"; //Anhängen wie in Python möglich
    std::cout << myText << std::endl;

    myText = myText + "!!";
    std::cout << myText << std::endl;

    int wPos = myText.find("W"); //Methode liefert Stelle zurück
    //weitere Methoden in Vorschlägen
    std::cout << wPos << std::endl;

    myText.insert(wPos, " "); //fügt Element an Position ein
    std::cout << myText << std::endl;

    return 0;
}

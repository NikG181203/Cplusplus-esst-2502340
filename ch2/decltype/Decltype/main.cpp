#include <iostream>
#include <string>

int main()
{
    std::string myText = "Hello World!!";

    std::cout << myText << std::endl;

    decltype(myText.find("W")) wPos = myText.find("W"); //findet Datantyp, wenn nicht deklariert
    std::cout << wPos << std::endl;

    myText.erase(wPos-1, 1); //löscht ein Element nach Position
    std::cout << myText << std::endl;

    return 0;
}

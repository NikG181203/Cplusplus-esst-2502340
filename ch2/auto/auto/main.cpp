#include <iostream>
#include <string>

int main()
{
    const std::string myText = "Genug Hello World!!"; //bei const sind "Variablen" nicht mehr veränderbar

    //const decltype(myText.find("H")) hPos = myText.find("h");
    const auto hPos = myText.find("H");
    std::cout << hPos << std::endl;

    const auto myTextPartial = myText.substr(hPos, std::string::npos); //npos -> gehe bis Ende von String
                                                                        //substring -> schneidet sich Teil aus String heraus

    std::cout << myTextPartial << std::endl;

    return 0;
}

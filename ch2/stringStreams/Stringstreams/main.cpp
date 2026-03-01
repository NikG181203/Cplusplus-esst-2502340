#include <iostream>
#include <sstream>
#include <array>

int main()
{
    std::stringstream ss; //elemente als string reinschreiben und in richtigem typ extrahieren

    std::array<int, 4> x;

    ss << "30 25 70.3";
    ss << "EtwasText"; //geht nicht zum auflösen, stringstream hängt hinten an

    ss >> x[0];
    ss >> x[1];
    ss >> x[2];
    ss >> x[3];

    for( const auto e : x) {
        std::cout << e << std::endl;
    }

    if ( (ss.rdstate() & std::stringstream::failbit ) != 0 ) {
      std::cerr << "Error: Not all values could be extracted correctly!" << std::endl;
    }


    return 0;
}


//stoi() -> string to integer
//stof() -> string to float
//to_string() -> wandelt in string
// C++ implementation​​​​​​‌‌‌‌​​​‌‌​‌​​​‌‌​​​​​‌‌​‌ below
// Uncomment these macros to control whether you see
// the expected result and/or hints.
#include <cstddef>
#include <string>
#define showExpectedResult
#define showHints

#include <iostream>
#include <vector>

#include <fstream>
#include <sstream>
#include <array>

constexpr int numRows = 4;
constexpr int numCols = 4;

using namespace std;


/**
 * @brief Liest aus Pfad "/tmp/deps/numbers.csv" die Datei ein.
 * @return Das file-Objekt 
*/
ifstream openNumbersFile()
{
    ifstream file("/tmp/deps/numbers.csv");
    // TODO: Hier muss file so angepasst werden, dass die Datei unter dem Pfad "/tmp/deps/numbers.csv" geöffnet wird.
    return file;
}

/**
 * @brief Liest aus file-Objekt die Matrix aus
 * @return Ein matrix-Objekt in welcher die ausgelesenen Zahlen stehen
 */
array< array<float, numCols>, numRows > readCsvTable(std::ifstream &file)
{
    array< array<float, numCols>, numRows > matrix;
    // TODO: Lies aus file die Zahlen und packe sie in das matrix-Objekt


    /* //kommt mit ifstream nicht als string!!!
    std::string line; //string definieren
    std::size_t row = 0; //zeilen auf 0 setzen

    while (row < numRows && std::getline(file, line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::size_t col = 0;

        while (col < numCols && std::getline(lineStream, cell, ' '))
        {
            matrix[row][col] = std::stof(cell);
            ++col;
        }

        ++row;
    }
    */
    for(uint i = 0; i<numRows; i++){
        for(uint j = 0; j<numCols; j++){
            //auto &row = matrix[i];
            file >> matrix[i][j]; 
        }
    }
    return matrix;
}

/**
 * @brief Berechnen der horizontalen Summen
 * @return Array aus Summen der Zeilen
 */
array<float, numRows> calcHorSums(const array< array<float, numCols>, numRows > &matrix)
{
    array<float, numCols> horSum;
    // TODO: Code zum berechnen der horizontalen Summen

    std::size_t row = 0;
    while(row < numRows){
        horSum[row] = matrix[row][0] + matrix[row][1] + matrix[row][2] + matrix[row][3];
        ++row;
    }
    return horSum;
}

/**
 * @brief Berechnen der vertikalen Summen
 * @return Array aus Summen der Spalten
 */
array<float, numCols> calcVertSums(const array< array<float, numCols>, numRows > &matrix)
{
    array<float, numCols> vertSum;
    // TODO: Code zum berechnen der vertikalen Summen

    std::size_t col = 0;
    while(col < numCols){
        vertSum[col] = matrix[0][col] + matrix[1][col] + matrix[2][col] + matrix[3][col];
        ++col;
    }
    return vertSum;
}

bool displaySums(const array<float, numCols> &horSum, 
                 const array<float, numRows> &vertSum)
{
    bool ok = true;    
    // TODO: Code zum Ausgeben der Summen. Bitte nicht mogeln ;-)
    for(const auto e : horSum){
        std::cout << e << std::endl;
    }
    cout << endl;
    for(const auto e: vertSum){
        std::cout << e << std::endl;
    }

    return ok;
}






// So wird Dein Code aufgerufen.
// Bitte so wenig wie möglich in diesem Bereich ändern (Sollte eigentlich auch nicht notwendig sein)
// Insbesondere die Variablen-Namen file, matrix, horSum, vertSum, ok dürfen nicht verändert werden.

std::ifstream file = openNumbersFile();

bool fileFound = false;

if(file.is_open())
    fileFound = true;
    
array< array<float, numCols>, numRows > matrix;
matrix = readCsvTable(file);

// Berechnung der Summen
array<float, numCols> horSum;
horSum = calcHorSums(matrix);
    
array<float, numRows> vertSum;    
vertSum = calcVertSums(matrix);

// Summen anzeigen
bool ok = displaySums(horSum, vertSum);


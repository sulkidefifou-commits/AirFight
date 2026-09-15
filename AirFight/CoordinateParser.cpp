
#include "CoordinateParser.h"
#include <charconv>
#include <limits>

bool CoordinateParser::TryParse(const std::string& coordinate, int& x, int& y) {

    std::size_t position = 0;
    int column = 0;

    //on prend une suite de char qui dois etre comprise entre A et Z, et on les convertie de la base 26 en decimal
    //nos lettre son obligatoirement des lettre majuscule
    while (position < coordinate.size()) {

        const char letter = coordinate[position];

        if (letter < 'A' || letter > 'Z') {
            break;
        }

        const int value = letter - 'A' + 1;

        column = column * 26 + value;

        ++position;
    }

    //check si au moins un chiffre suis coordinates
    if (position == 0 || position == coordinate.size() || coordinate[position] < '1' || coordinate[position] > '9') {


        return false;

    }

    int row;//initialisation de nos caracter chiffre en valeur int
    const char* begin = coordinate.data() + position; //notre premier caracter chiffre
    const char* end = coordinate.data() + coordinate.size(); //notre dernier caracter chiffre


    // convertit la partie numerique et indique ou la lecture s'arrete (lib charconv)
    std::from_chars(begin, end, row);

    x = column - 1;
    y = row - 1;

    return true;

}

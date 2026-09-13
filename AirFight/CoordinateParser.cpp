
#include "CoordinateParser.h"
#include <charconv>
#include <limits>

bool CoordinateParser::TryParse(const std::string& coordinate, int& x, int& y) {

    std::size_t position = 0;
    int column = 0;

    //on prend une suite de char qui dois etre comprise entre A et Z, et on les convertie de la base 26 en decimal
    while (position < coordinate.size()) {

        const char letter = coordinate[position];

        if (letter < 'A' || letter > 'Z') {
            break;
        }

        const int value = letter - 'A' + 1;

        // Verifie que le calcul suivant tient dans un int.
        if (column > (std::numeric_limits<int>::max() - value) / 26) {
            return false;
        }

        column = column * 26 + value;

        ++position;
    }

    if (position == 0 || position == coordinate.size() || coordinate[position] < '1' || coordinate[position] > '9') {

        return false;

    }

    int row = 0;
    const char* begin = coordinate.data() + position;
    const char* end = coordinate.data() + coordinate.size();


    // Convertit la partie numerique et indique ou la lecture s'arrete.
    const std::from_chars_result conversion = std::from_chars(begin, end, row);

    // Echec de conversion ou nombre trop grand pour un int.
    if (conversion.ec != std::errc{}) {
        return false;
    }

    // Il reste un caractere apres le nombre, par exemple le X de B7X.
    if (conversion.ptr != end) {
        return false;
    }

    //on change x et y car on affecte une ref

    x = column - 1;
    y = row - 1;
    return true;

}

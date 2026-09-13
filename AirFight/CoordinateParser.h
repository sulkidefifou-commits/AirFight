//
// Created by Sulkide on 12/09/2026.
//

#ifndef AIRFIGHT_COORDINATEPARSER_H
#define AIRFIGHT_COORDINATEPARSER_H
#include <string>

// traduction des valeur numérique en coordonnée de tile alphanumérique

class CoordinateParser {

    public:
        static bool TryParse(const std::string& coordinate, int& x, int& y);
};


#endif //AIRFIGHT_COORDINATEPARSER_H

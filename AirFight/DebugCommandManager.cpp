#include "DebugCommandManager.h"
#include "CoordinateParser.h"
#include "Grid.h"
#include "TileData.h"
#include <iostream>
#include <sstream>

bool DebugCommandManager::Execute(const std::string& line) {
    std::istringstream input(line);
    std::string command;
    std::string coordinate;
    std::string extra;

    input >> command >> coordinate >> extra;

    if (command.empty()) {
        return true;
    }

    if (command == "QUIT") {
        return false;
    }


    if (command == "CHECK") {
        int x;
        int y;

        if (!CoordinateParser::TryParse(coordinate, x, y)) {
            std::cout << "coordonnee invalide.\n";
            return true;
        }

        const uint8_t* tile = Grid::GetTileAt(x, y);

        if (tile == nullptr) {
            std::cout << "case hors grille ou sans donnees.\n";
        } else {
            std::cout << coordinate << " -> " << TileData::GetTypeName(tile) << '\n';
        }

        return true;
    }

    return true;

}

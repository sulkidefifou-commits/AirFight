#include "CommandManager.h"
#include "CoordinateParser.h"
#include "Grid.h"
#include "TileData.h"
#include <charconv>
#include <iostream>
#include <sstream>

#include "GameManager.h"

bool CommandManager::Execute(const std::string& line) {
    std::istringstream input(line);
    std::string command;
    std::string coordinate;
    std::string extra;

    input >> command;
    if (command.empty()) {
        return true;
    }

    if (command == "HELP") {

        std::cout << std::endl

        << "----Information----\n"<< std::endl

        << "taille de carte minimal : 13 x 13\n"
        << "taille de carte maximal : 30 x 30\n" << std::endl

        << "!!! il est preferable d'ecrire une commande en majuscule !!!\n" << std::endl

        << "si la carte est trop grand pour la taille de la fenetre, dezoomez avec CTRL + Molette\n"<< std::endl<< std::endl

        << "----List de commands----\n"<< std::endl

        << "1) CREATE [x] [y] [tile] -> permet de creer une carte selon une longueur X, une largeur y et un type de tile \n"
        <<  "EXEMPLE : CREATE 20 18 SQUARE\n"<< std::endl

        << "2) REPLACE [alphaNum] [tile] -> permet de remplace un tile existant selon sa coordonne alphanNumerique en un type de tile choisie \n"
        <<  "EXEMPLE : REPLACE B7 FULL\n"<< std::endl

        << "3) CHECK [alphaNum] -> permet de retourner le type de tile d'un coordonne alphaNumerique\n"
        <<  "EXEMPLE : CHECK B7\n"<< std::endl

        << "4) QUIT -> termine le programme\n"<< std::endl<< std::endl

        << "----List des type de tile----\n"<< std::endl

        << "- SQUARE\n"
        << "- EMPTY\n"
        << "- FULL\n"
        << "- DEBUG\n"

        << std::endl;

        return true;
    }

    if (command == "QUIT") {
        return false;
    }



    if (command == "CREATE") {
        std::string widthText;
        std::string heightText;
        std::string tileType;


        if (!(input >> widthText >> heightText >> tileType)) {
            std::cout << "Erreur : \n"
                    <<" format attendu CREATE longueur largeur TYPE.\n"
                    << "Exemple : CREATE 20 15 SQUARE\n";
            return true;
        }

        int width;
        int height;

        std::from_chars(widthText.data(), widthText.data() + widthText.size(), width);
        std::from_chars(heightText.data(), heightText.data() + heightText.size(), height);


        if (width < Grid::GridMinWidth || width > Grid::GridMaxWidth ||height < Grid::GridMinHeight || height > Grid::GridMaxHeight) {
            std::cout << "Erreur : \n"
                    <<  "  longueur (colonnes) entre " << Grid::GridMinWidth
                    << " et " << Grid::GridMaxWidth
                    << ", largeur (lignes) entre " << Grid::GridMinHeight
                    << " et " << Grid::GridMaxHeight << ".\n";
            return true;
        }

        const uint8_t* newTile;

        if (tileType == "EMPTY") {
            newTile = TileData::Empty;
        }
        else if (tileType == "FULL") {
            newTile = TileData::Full;
        }
        else if (tileType == "SQUARE") {
            newTile = TileData::Square;
        }
        else if (tileType == "DEBUG") {
            newTile = TileData::Debug;
        }
        else {
            std::cout << "Erreur : \n" <<"Type inconnu : utilisez EMPTY, FULL, SQUARE ou DEBUG.\n";
            return true;
        }

        GameManager::Instance()->CreateMap(width, height, newTile);

        std::cout << "Grille creer : " << width << " x " << height
                  << " tile de type " << tileType << ".\n";
        return true;
    }


    input >> coordinate >> extra;
    if (command == "CHECK") {
        int x;
        int y;

        if (!CoordinateParser::TryParse(coordinate, x, y)) {
            std::cout << "Erreur : \n"<<" Coordonnee invalide.\n";
            return true;
        }

        const uint8_t* tile = Grid::GetTileAt(x, y);

        if (tile == nullptr) {
            std::cout << "Erreur : \n" <<"Case hors grille ou sans donnees.\n";
        } else {
            std::cout << coordinate << " -> " << TileData::GetTypeName(tile) << '\n';
        }

        return true;
    }

    if (command == "REPLACE") {


        if (coordinate.empty() || extra.empty()) {
            std::cout << "Erreur : \n"
                    <<" format attendue : REPLACE B1 SQUARE\n";
            return true;
        }


        const uint8_t* newTile;

        if (extra == "EMPTY") {
            newTile = TileData::Empty;
        }
        else if (extra == "FULL") {
            newTile = TileData::Full;
        }
        else if (extra == "SQUARE") {
            newTile = TileData::Square;
        }
        else if (extra == "DEBUG") {
            newTile = TileData::Debug;
        }
        else {
            std::cout << "Erreur : \n"
                    <<"Type inconnu : utilisez EMPTY, FULL, SQUARE ou DEBUG.\n";
            return true;
        }

        GameManager::Instance()->HardReplaceTileAtValue(coordinate, newTile);

        std::cout << coordinate << " remplacer par " << extra << ".\n";

        return true;
    }



    std::cout << "Erreur : \n"
            <<"commande invalide : utilisez [QUIT] pour fermer le programme.\n";

    return true;

}
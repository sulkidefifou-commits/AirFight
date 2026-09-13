#include "InputManager.h"
#include <iostream>

bool InputManager::ReadLine(std::string& line) {

    if (!std::getline(std::cin, line)) {

        return false;

    }

    for (char& character : line) {

        character = static_cast<char>(std::toupper(static_cast<unsigned char>(character))); //commande toupper transforme les char min en maj
    }

    return true;
}



#include <iostream>

#include "DebugCommandManager.h"
#include "GameManager.h"
#include "InputManager.h"

using namespace std;

int main()
{

    GameManager::Instance()->CreateDebugMap();

    std::string line;

    while (true) {
        std::cout << "> " << std::flush;

        if (!InputManager::ReadLine(line) || !DebugCommandManager::Execute(line)) {
            break;
        }
    }

}


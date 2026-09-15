
#include <iostream>
#include "CommandManager.h"
#include "GameManager.h"
#include "InputManager.h"

#include <windows.h>

using namespace std;

int main()
{

    std::string line;

    //----------------------------------------------------------------------------------------------------------------//

    //Parametre permettant de donné l'acces au programme a la modification de l'inviter de commande, trouver grace a :
    // https://learn.microsoft.com/fr-fr/windows/console/clearing-the-screen?utm_source=chatgpt.com#example-1

    HANDLE hStdOut  = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;

    if (GetConsoleMode(hStdOut , &mode)) {

        SetConsoleMode(hStdOut ,mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }

    //----------------------------------------------------------------------------------------------------------------//


    cout
    << endl
    << "----Tapez [HELP] pour afficher les aides et information----\n"
    << endl;


    while (true) {
        std::cout << "> " << std::flush; //flush permet de vider le buffer sans sauter la ligne comme endl

        if (!InputManager::ReadLine(line) || !CommandManager::Execute(line)) {
            break;
        }
    }

}


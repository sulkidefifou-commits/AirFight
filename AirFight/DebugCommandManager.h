
#ifndef AIRFIGHT_DEBUGCOMMANDMANAGER_H
#define AIRFIGHT_DEBUGCOMMANDMANAGER_H
#include <string>

//reconnais une commande et verifie ses argument puis déclanche un evenement debogage

class DebugCommandManager {

    public:
        static bool Execute(const std::string& line);

};


#endif //AIRFIGHT_DEBUGCOMMANDMANAGER_H

#ifndef AIRFIGHT_GAMEMANAGER_H
#define AIRFIGHT_GAMEMANAGER_H
#include <cstdint>
#include <string>

#include "TileData.h"


class GameManager {

    private:
        static GameManager* instance;

        GameManager(){}

        int currentGridWidth = 13;
        int currentGridHeight = 13;
        int RefreshVideoValue = 100;



    public:
        static GameManager* Instance() {

            if (instance == nullptr) {

                instance = new GameManager();

            }

            return instance;
        }

        void CreateMap(int GridWidth = 13, int GridHeight = 13, const uint8_t Debug[16] = TileData::Debug);

        void SetCurrentGridWidth(int value);
        void SetCurrentGridHeight(int value);
        void SetRefreshVideoValue(int value);

        int GetCurrentGridWidth() const;
        int GetCurrentGridHeight() const;
        int GetRefreshVideoValue() const;

        int GetCurrentPixelNumberPerRow() const;
        int GetCurrentPixelNumberPerColumn() const;

        int GetTotalNumberOfTiles() const;

        static void HardReplaceTileAtValue(const std::string& coordinate,const uint8_t* newTile);
};


#endif //AIRFIGHT_GAMEMANAGER_H

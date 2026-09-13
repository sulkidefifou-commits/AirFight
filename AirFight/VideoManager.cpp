
#include "VideoManager.h"
#include <iostream>
#include <vector>

#include "Tile.h"

using namespace std;

VideoManager* VideoManager::instance = nullptr;

void VideoManager::DisplayMap() const {
    const int width = GameManager::Instance()->GetCurrentGridWidth();
   // const int height = GameManager::Instance()->GetCurrentGridHeight();
    const int pixelWidth = GameManager::Instance()->GetCurrentPixelNumberPerRow();
    const int pixelHeight = GameManager::Instance()->GetCurrentPixelNumberPerColumn();


    constexpr char characters[4] = {

        char(Tile::CharWhitePixel),
        char(Tile::CharGrayPixel),
        char(Tile::CharDarkPixel),
        char(Tile::CharBlackPixel)

    };



    for (int y = 0; y < pixelHeight; ++y) {

        const int tileRow = (y / 8) * width; //division en entier donne l'arrondie a min
        const int pixelY = y % 8; // ligne de pixel du tile

        for (int x = 0; x < pixelWidth; ++x)
        {
            const uint8_t* tile = currentMap[tileRow + x / 8]; //index du start d'un ranger + la colone actuelle d'un tile = l'index du tile dans la carte
            const int pixelX = x % 8; // colonne de pixel du tile

            const int byteIndex = pixelY * 2 + pixelX / 4; //pour un tile on fais, ligne * 2 (une ligne vaux 2 octect) + le premier ou 2eme octect
            const int shift = 6 - (pixelX % 4) * 2;

            const uint8_t pixel = (tile[byteIndex] >> shift) & 0b00000011;

            std::cout << characters[pixel] << characters[pixel];
        }

        std::cout << '\n';
    }
}

void VideoManager::SetCurrentMap(const std::vector<const uint8_t *> &map) {

    currentMap = map;

}

std::vector<const uint8_t *> VideoManager::GetCurrentMap() {

    return currentMap;

}

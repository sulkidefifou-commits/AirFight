

#include "GameManager.h"

#include <vector>

#include "CoordinateParser.h"
#include "Grid.h"
#include "Tile.h"
#include "VideoManager.h"

GameManager* GameManager::instance = nullptr;

void GameManager::CreateMap(int GridWidth, int GridHeight, const uint8_t Debug[16]){

    SetCurrentGridWidth(GridWidth);
    SetCurrentGridHeight(GridHeight);

    std::vector<const uint8_t*> mapDebug(GetTotalNumberOfTiles(), Debug);

    VideoManager::Instance()->SetCurrentMap(mapDebug);

    VideoManager::Instance()->DisplayMap();

}


void GameManager::SetCurrentGridWidth(int value) {

    if (value < Grid::GridMinWidth) {
        currentGridWidth = Grid::GridMinWidth;
        return;
    }

    currentGridWidth = value;

}

void GameManager::SetCurrentGridHeight(int value) {

    if (value < Grid::GridMinHeight) {
        currentGridHeight = Grid::GridMinHeight;
        return;
    }

    currentGridHeight = value;
}

void GameManager::SetRefreshVideoValue(int value) {

    RefreshVideoValue = value;

}

int GameManager::GetCurrentGridWidth() const {

    return currentGridWidth;

}

int GameManager::GetCurrentGridHeight() const {

    return currentGridHeight;
}

int GameManager::GetRefreshVideoValue() const {

    return RefreshVideoValue;
}

int GameManager::GetCurrentPixelNumberPerRow() const {

    return currentGridWidth * Tile::Wight;

}

int GameManager::GetCurrentPixelNumberPerColumn() const {

    return currentGridHeight * Tile::Height;

}

int GameManager::GetTotalNumberOfTiles() const {

    return currentGridWidth*currentGridHeight;
}

void GameManager::HardReplaceTileAtValue(const std::string &coordinate, const uint8_t *newTile) {

    int x;
    int y;

    if (!CoordinateParser::TryParse(coordinate, x, y)) {
        return;
    }

    const int width = Instance()->GetCurrentGridWidth();
    const int height = Instance()->GetCurrentGridHeight();

    if (x < 0 || y < 0 || x >= width || y >= height) {
        return;
    }

    const std::size_t index = static_cast<std::size_t>(y) * width + x;

    VideoManager::Instance()->SetTileAtIndex(index, newTile);


}

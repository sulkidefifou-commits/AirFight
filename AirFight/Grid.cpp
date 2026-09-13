

#include "Grid.h"

#include "GameManager.h"
#include "VideoManager.h"


const uint8_t* Grid::GetTileAt(int x, int y) {
    const int width = GameManager::Instance()->GetCurrentGridWidth();
    const int height = GameManager::Instance()->GetCurrentGridHeight();

    if (x < 0 || y < 0 || x >= width || y >= height) {
        return nullptr;
    }

    const std::vector<const uint8_t*> &map = VideoManager::Instance()->GetCurrentMap();

    const std::size_t index = static_cast<std::size_t>(y) * width + x;

    if (index >= map.size()) {
        return nullptr;
    }

    return map[index];


}

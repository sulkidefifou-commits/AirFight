
#ifndef AIRFIGHT_GRID_H
#define AIRFIGHT_GRID_H
#include <cstdint>


class Grid {

public:
    static constexpr int GridMinWidth = 13;
    static constexpr int GridMinHeight = 13;

    static const uint8_t* GetTileAt(int x, int y);

    void HardReplaceTileAtValue();
    void SoftReplaceTileAtValue();
    void UnReplaceTileAtValue();

};


#endif //AIRFIGHT_GRID_H

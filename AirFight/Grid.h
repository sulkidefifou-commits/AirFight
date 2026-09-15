
#ifndef AIRFIGHT_GRID_H
#define AIRFIGHT_GRID_H
#include <cstdint>
#include <string>


class Grid {

public:
    static constexpr int GridMinWidth = 13;
    static constexpr int GridMinHeight = 13;

    static constexpr int GridMaxWidth = 30;
    static constexpr int GridMaxHeight = 30;

    static const uint8_t* GetTileAt(int x, int y);


};


#endif //AIRFIGHT_GRID_H

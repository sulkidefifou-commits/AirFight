
#ifndef AIRFIGHT_GRID_H
#define AIRFIGHT_GRID_H


class Grid {

public:
    static constexpr int GridMinWidth = 13;
    static constexpr int GridMinHeight = 13;

    void HardReplaceTileAtValue();
    void SoftReplaceTileAtValue();
    void UnReplaceTileAtValue();

};


#endif //AIRFIGHT_GRID_H

#ifndef AIRFIGHT_VIDEO_H
#define AIRFIGHT_VIDEO_H
#include <cstdint>
#include <list>
#include <vector>

#include "GameManager.h"


class VideoManager {

    private:

        static VideoManager* instance;

        VideoManager(){}

        std::vector<const uint8_t*> currentMap;

    public:

        static VideoManager* Instance() {

            if (instance == nullptr) {

                instance = new VideoManager();

            }

            return instance;
        }

        void DisplayMap() const;

        void SetCurrentMap(const std::vector<const uint8_t*> &map);

        const std::vector<const uint8_t*>& GetCurrentMap() const;
};


#endif //AIRFIGHT_VIDEO_H

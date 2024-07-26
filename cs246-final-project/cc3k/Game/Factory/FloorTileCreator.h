#ifndef CELLCREATOR_H
#define CELLCREATOR_H

#include "Creator.h"
#include "../Floor/Cell/Cell.h"
#include "../Floor/Cell/FloorTile.h"


class CellCreator : public Creator {
    public:
        std::shared_ptr<Tile> spawnFloorTile(int x, int y, int room_number, bool is_rand_generated = false) override {
            std::shared_ptr<Tile> newCell;
            newCell = make_shared<FloorTile>(x, y, room_number);
            return newCell;
        }
};

#endif

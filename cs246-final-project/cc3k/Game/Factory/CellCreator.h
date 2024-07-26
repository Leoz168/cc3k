#ifndef CELLCREATOR_H
#define CELLCREATOR_H

#include "Creator.h"
#include "../Floor/Cell/Cell.h"
#include "../Floor/Cell/FloorTile.h"
#include "../Floor/Cell/Doorway.h"
#include "../Floor/Cell/HWall.h"
#include "../Floor/Cell/VWall.h"
#include "../Floor/Cell/Passage.h"
#include "../Floor/Cell/Stair.h"
#include "../Floor/BlankTile.h"


class CellCreator : public Creator {
    public:
        std::unique_ptr<Tile> spawnTile(int x, int y, int id = NOTHING, bool is_rand_generated = false) override {
            std::unique_ptr<Tile> newCell;

            switch (id) {
                case FLOORTILE:
                    newCell = make_unique<FloorTile>(x, y);
                    break;
                case HWALL:
                    newCell = make_unique<HWall>(x, y);
                    break;
                case VWALL:
                    newCell = make_unique<VWall>(x, y);
                    break;
                case PASSAGE:
                    newCell = make_unique<Passage>(x, y);
                    break;
                case DOORWAY:
                    newCell = make_unique<Doorway>(x, y);
                    break;
                case STAIR:
                    newCell = make_unique<Stair>(x, y);
                    break;
                default:
                    newCell = make_unique<BlankTile>(x, y);
                    break;
            }

            return newCell;
            
        }
};

#endif

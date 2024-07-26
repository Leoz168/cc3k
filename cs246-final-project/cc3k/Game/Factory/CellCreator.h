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
        std::shared_ptr<Tile> spawnTile(int x, int y, int id = NOTHING, bool is_rand_generated = false) override {
            std::shared_ptr<Tile> newCell;

            switch (id) {
                case FLOORTILE:
                    newCell = make_shared<FloorTile>(x, y);
                    break;
                case HWALL:
                    newCell = make_shared<HWall>(x, y);
                    break;
                case VWALL:
                    newCell = make_shared<VWall>(x, y);
                    break;
                case PASSAGE:
                    newCell = make_shared<Passage>(x, y);
                    break;
                case DOORWAY:
                    newCell = make_shared<Doorway>(x, y);
                    break;
                case STAIR:
                    newCell = make_shared<Stair>(x, y);
                    break;
                default:
                    newCell = make_shared<BlankTile>(x, y);
                    break;
            }

            return newCell;
            
        }
};

#endif

#ifndef CELLCREATOR_H
#define CELLCREATOR_H

#include "Creator.h"
#include "Cell.h"
#include "FloorTile.h"
#include "Doorway.h"
#include "HWall.h"
#include "VWall.h"
#include "Passage.h"
#include "Stair.h"
#include "BlankTile.h"


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

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

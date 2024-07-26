#ifndef CREATOR_H
#define CREATOR_H

#include <map>
#include <cstdlib>
#include <memory>

#include "../tileGenConsts.h"
#include "../Tile.h"
#include "../tileIDs.h"

class EffectHandler;

class Creator {
    protected:
        // creates a Player object
        virtual std::shared_ptr<Player> spawnPlayer(int x, int y, int id) {
            return nullptr;
        }

        // creates a Tile specified by id (used for creating Potion, Gold, Cell, Enemy).
        virtual std::shared_ptr<Tile> spawnTile(int x, int y, int id = NOTHING, bool is_rand_generated = false) {
            return nullptr;
        }

        // creates a FloorTile with room specified by room_number.
        virtual std::shared_ptr<Tile> spawnFloorTile(int x, int y, int room_num = NOASSOCIATEDROOM, bool is_rand_generated = false) {
            return nullptr;
        }

    public:
        virtual ~Creator() = default;
};

#endif

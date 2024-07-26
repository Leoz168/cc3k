#ifndef CREATOR_H
#define CREATOR_H

#include <map>
#include <cstdlib>
#include <memory>

#include "../Tile.h"
#include "../tileIDs.h"

class EffectHandler;

class Creator {
    protected:
        // creates a Player object
        virtual std::unique_ptr<Tile> spawnPlayer(int x, int y, int id) {
            return nullptr;
        }

        // creates a Tile specified by id (used for creating Potion, Gold, Cell, Enemy).
        virtual std::shared_ptr<Tile> spawnTile(int x, int y, int id = NOTHING, bool is_rand_generated = false) {
            return nullptr;
        }

    public:
        virtual ~Creator() = 0;
};

#endif
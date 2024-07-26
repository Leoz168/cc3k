#ifndef TILE_H
#define TILE_H

#include <utility>
#include <vector>
#include <memory>
#include "tileGenConsts.h"
#include "tileIDs.h"
using namespace std;

class Player;
class GameMap;

class Tile {
    protected:
        int x, y;
        int id;
        int room_number;
        int tile_type;
    public:
        Tile(int x, int y, int id, int room_number = NOASSOCIATEDROOM, int tile_type = NOTYPE);

        // getTileID gets the unique tile id defined in the consts.h file
        // Default: returns this class' id field
        virtual int getTileID();

        virtual int getTileType();

        // getTilePtr gets the ptr to the Tile object
        virtual Tile* getTilePtr() = 0;

        virtual int getRoomNumber();

        // move moves the Tile by (dx, dy), if the thing there is movable.
        //     Returns whether the thing was moved or not.
        // Default: does nothing, returns false
        virtual bool move(int dx, int dy, GameMap& map);

        // takeAction lets the Tile take a "turn". For example, an enemy would move
        //     or attack the player. The function returns whether or not the tile
        //     should be despawned after it takes action.
        // Default: does nothing
        virtual bool takeAction(Player*, GameMap& map);

        virtual pair<int, int> getPosn();

        virtual ~Tile() = default;
};

#endif

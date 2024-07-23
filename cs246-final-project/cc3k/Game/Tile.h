#ifndef TILE_H
#define TILE_H

#include <utility>
using namespace std;

class Tile {
        int x, y;
    public:
        Tile(int x, int y);

        // getTileID gets the unique tile id defined in the consts.h file for the given coordinates
        virtual int getTileID(int x, int y) = 0;

        // getTilePtr gets the ptr to the Floor object at (x, y)
        virtual Tile* getTilePtr(int x, int y) = 0;

        // move moves the file at (x, y) by (dx, dy), if the thing there is movable 
        virtual bool move(int x, int y, int dx, int dy) = 0;

        // playerAttack triggers a player attack on the tile at (x, y). It returns <bool, bool>,
        //     where the first value is whether the attack was successful or not, and the
        //     second value is whether an entity was killed or not
        virtual std::pair<bool, bool> playerAttack(int x, int y) = 0;

        // playerUsed triggers a player use action on the tile at (x, y). It returns a bool,
        //     which indicates whether the use was successful or not.
        virtual bool playerUsed(int x, int y) = 0;

        // takeAction lets the tile at (x, y) take a turn. For example, an enemy would move
        //     or attack the player. The function returns whether or not the tile
        //     should be despawned after it takes action.
        virtual bool takeAction(int x, int y) = 0;

        virtual ~Tile() = 0;
};

#endif

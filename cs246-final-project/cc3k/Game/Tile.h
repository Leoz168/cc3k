#ifndef TILE_H
#define TILE_H

#include <utility>
using namespace std;

class Tile {
    protected:
        int x, y;
        int id;
    public:
        Tile(int x, int y, int id);

        // getTileID gets the unique tile id defined in the consts.h file
        // Default: returns this class' id field
        virtual int getTileID();

        // getTilePtr gets the ptr to the Tile object
        virtual Tile* getTilePtr() = 0;

        // move moves the Tile by (dx, dy), if the thing there is movable
        // Default: does nothing
        virtual bool move(int dx, int dy);

        // playerAttack triggers a player attack on the Tile. It returns <bool, bool>,
        //     where the first value is whether the attack was successful or not, and the
        //     second value is whether an entity was killed or not
        // Default: does nothing
        virtual std::pair<bool, bool> playerAttack();

        // playerUsed triggers a player use action on the Tile. It returns a bool,
        //     which indicates whether the use was successful or not.
        // Default: does nothing
        virtual bool playerUsed();

        // takeAction lets the Tile take a "turn". For example, an enemy would move
        //     or attack the player. The function returns whether or not the tile
        //     should be despawned after it takes action.
        // Default: does nothing
        virtual bool takeAction();

        virtual ~Tile() = 0;
};

#endif

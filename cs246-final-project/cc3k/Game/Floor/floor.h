#include <utility>
using namespace std;
class Floor {
    public:
        // getTileID gets the unique tile id defined in the consts.h file for the given coordinates
        virtual int getTileID(int x, int y);

        // getTilePtr gets the ptr to the Floor object at (x, y)
        virtual Floor* getTilePtr(int x, int y);

        // move moves the file at (x, y) by (dx, dy), if the thing there is movable 
        virtual bool move(int x, int y, int dx, int dy);

        // playerAttack triggers a player attack on the tile at (x, y). It returns <bool, bool>,
        //     where the first value is whether the attack was successful or not, and the
        //     second value is whether an entity was killed or not
        virtual std::pair<bool, bool> playerAttack(int x, int y);

        // playerUsed triggers a player use action on the tile at (x, y). It returns a bool,
        //     which indicates whether the use was successful or not.
        virtual bool playerUsed(int x, int y);

        // takeAction lets the tile at (x, y) take a turn. For example, an enemy would move
        //     or attack the player.
        virtual bool takeAction(int x, int y);

        virtual ~Floor() = 0;
};

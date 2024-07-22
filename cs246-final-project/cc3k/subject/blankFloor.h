#include "floor.h"
class BlankFloor: public Floor {
        int type;
    public:
        BlankFloor(int x, int y);
        int getTileID(int x, int y) {}
};

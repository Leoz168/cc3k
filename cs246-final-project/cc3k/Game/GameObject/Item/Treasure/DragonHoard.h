#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H

#include "Gold.h"

using namespace std;

class DragonHoard : public Gold {
        bool is_dragon_alive;
    public:
        DragonHoard(int x, int y, bool is_dragon_alive = true);
        Tile* getTilePtr() override;
        string getDescription() override;

        // Returns true if and only if dragon is dead, false iff dragon is alive
        bool canPlayerPickup(Player* player) override;

        // sets state of dragon, true for alive, false for dead
        void setDragonStatus(bool dragon_status);

        int getGoldValue();
        
        ~DragonHoard();
};

#endif

#ifndef DRAGON_H
#define DRAGON_H

#include "Enemy.h"
#include "../Item/Treasure/DragonHoard.h"
#include <memory>

using namespace std;

class Dragon : public Enemy {
        shared_ptr<DragonHoard> hoard;
        void preAction(Player* player, GameMap& map) override;
        void postAtkedByPlayerAction(Player* player) override;
    public:
        Dragon(int x, int y, shared_ptr<DragonHoard> hoard);
        Tile* getTilePtr() override;
        bool takeAction(Player* player, GameMap& map) override;
        ~Dragon();
};


#endif

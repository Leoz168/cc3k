#ifndef DRAGON_H
#define DRAGON_H

#include "Enemy.h"
#include "DragonHoard.h"
#include <memory>

using namespace std;

class Dragon : public Enemy {
        shared_ptr<DragonHoard> hoard;
        void preAction(Player* player, GameMap& map) override;
    public:
        Dragon(int x, int y, shared_ptr<DragonHoard> hoard);
        Tile* getTilePtr() override;
        bool takeAction(Player* player, GameMap& map) override;
        ~Dragon();
};


#endif

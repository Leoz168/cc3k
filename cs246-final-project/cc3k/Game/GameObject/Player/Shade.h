#ifndef SHADE_H
#define SHADE_H

#include "Player.h"

class Shade : public Player {
    public:
        Shade(int x, int y);
        bool attackEnemy(Enemy * e);
        void attackedBy(Enemy * e);
        int getTileID() override;
        Tile* getTilePtr() override;
        bool triggerAbility(int id, int ab_ver) override;
        ~Shade() = default;
};

#endif

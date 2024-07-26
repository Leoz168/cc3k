#ifndef TROLL_H
#define TROLL_H

#include "Player.h"

class Troll : public Player {
    public:
        Troll(int x, int y);
        bool attackEnemy(Enemy * e);
        void attackedBy(Enemy * e);
        int getTileID() override;
        Tile* getTilePtr() override;
        bool triggerAbility(int id, int ab_ver);
        ~Troll() = default;
};

#endif

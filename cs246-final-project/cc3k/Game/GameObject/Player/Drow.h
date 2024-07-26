#ifndef DROW_H
#define DROW_H

#include "Player.h"

class Drow : public Player {
    public:
        Drow(int x, int y);
        bool attackEnemy(Enemy * e);
        void attackedBy(Enemy * e);
        int getTileID() override;
        Tile* getTilePtr() override;
        bool triggerAbility(int id, int ab_ver);
        ~Drow() = default;
};

#endif

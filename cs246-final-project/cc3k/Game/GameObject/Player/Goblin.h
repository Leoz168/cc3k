#ifndef GOBLIN_H
#define GOBLIN_H

#include "Player.h"

class Goblin : public Player {
    public:
        Goblin(int x, int y);
        bool attackEnemy(Enemy * e);
        void attackedBy(Enemy * e);
        bool triggerAbility(int id, int ab_ver);
        ~Goblin() = default;
};

#endif

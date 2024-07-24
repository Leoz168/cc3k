#ifndef GOBLIN_H
#define GOBLIN_H

#include "Player.h"
#include "tileIDs.h"

class Goblin : public Player {
    public:
        Goblin(int x, int y, EffectHandler* ehr);
        bool attackEnemy(Enemy * e);
        bool attackedBy(Enemy * e);
        bool triggerAbility(int id, int ab_ver);
        ~Goblin() = default;
};

#endif

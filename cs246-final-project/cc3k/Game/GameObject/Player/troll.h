#ifndef TROLL_H
#define TROLL_H

#include "Player.h"
#include "tileIDs.h"

class Troll : public Player {
    public:
        Troll(int x, int y, EffectHandler* ehr);
        bool attackEnemy(Enemy * e);
        bool attackedBy(Enemy * e);
        bool triggerAbility(int id, int ab_ver);
        ~Troll() = default;
};

#endif

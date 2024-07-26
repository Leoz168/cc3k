#ifndef DROW_H
#define DROW_H

#include "Player.h"

class Drow : public Player {
    public:
        Drow(int x, int y, EffectHandler* ehr);
        bool attackEnemy(Enemy * e);
        void attackedBy(Enemy * e);
        bool triggerAbility(int id, int ab_ver);
        ~Drow() = default;
};

#endif

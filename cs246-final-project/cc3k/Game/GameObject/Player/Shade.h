#ifndef SHADE_H
#define SHADE_H

#include "Player.h"

class Shade : public Player {
    public:
        Shade(int x, int y, EffectHandler* ehr);
        bool attackEnemy(Enemy * e);
        void attackedBy(Enemy * e);
        bool triggerAbility(int id, int ab_ver);
        ~Shade() = default;
};

#endif

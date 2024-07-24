#ifndef SHADE_H
#define SHADE_H

#include "Player.h"
#include "tileIDs.h"

class Shade : public Player {
    public:
        Shade(int x, int y, EffectHandler* ehr);
        bool attackEnemy(Enemy * e);
        bool attackedBy(Enemy * e);
        bool triggerAbility(int id, int ab_ver);
        ~Shade() = default;
};

#endif

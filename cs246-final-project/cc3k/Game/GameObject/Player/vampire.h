#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Player.h"
#include "tileIDs.h"

class Vampire : public Player {
    public:
        Vampire(int x, int y, EffectHandler* ehr);
        bool attackEnemy(Enemy * e);
        bool attackedBy(Enemy * e);
        bool triggerAbility(int id, int ab_ver);
        ~Vampire() = default;
};

#endif

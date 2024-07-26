#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Player.h"

class Vampire : public Player {
    public:
        Vampire(int x, int y);
        bool attackEnemy(Enemy * e);
        void attackedBy(Enemy * e);
        bool triggerAbility(int id, int ab_ver);
        ~Vampire() = default;
};

#endif

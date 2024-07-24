#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Player.h"
#include "tileIDs.h"

class Vampire : public Player {
public:
    Vampire(int x, int y, EffectHandler* ehr);
};

#endif

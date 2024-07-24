#ifndef SHADE_H
#define SHADE_H

#include "Player.h"
#include "tileIDs.h"

class Shade : public Player {
public:
    Shade(int x, int y, EffectHandler* ehr);
};

#endif

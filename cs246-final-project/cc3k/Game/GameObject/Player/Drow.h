#ifndef DROW_H
#define DROW_H

#include "Player.h"
#include "tileIDs.h"

class Drow : public Player {
public:
    Drow(int x, int y, EffectHandler* ehr);
};

#endif

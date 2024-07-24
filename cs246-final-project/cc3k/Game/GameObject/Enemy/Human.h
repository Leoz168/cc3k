#ifndef HUMAN_H
#define HUMAN_H

#include "Enemy.h"

using namespace std;

class Human : public Enemy {
    public:
        Human(int x, int y);
        Tile* getTilePtr() override;
        ~Human();
};


#endif

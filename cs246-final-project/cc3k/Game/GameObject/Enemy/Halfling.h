#ifndef HALFLING_H
#define HALFLING_H

#include "Enemy.h"

using namespace std;

class Halfling : public Enemy {
    public:
        Halfling(int x, int y);
        Tile* getTilePtr() override;
        std::pair<bool, bool> atkedByPlayer(Player*) override;
        ~Halfling();
};


#endif

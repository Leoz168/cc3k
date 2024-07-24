#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

using namespace std;

class Orc : public Enemy {
    public:
        Orc(int x, int y);
        Tile* getTilePtr() override;
        ~Orc();
};


#endif

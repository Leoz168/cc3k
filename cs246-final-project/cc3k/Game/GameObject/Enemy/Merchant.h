#ifndef MERCHANT_H
#define MERCHANT_H

#include "Enemy.h"

using namespace std;

class Merchant : public Enemy {
        void preAction(Player* player, GameMap& map) override;
    public:
        Merchant(int x, int y);
        Tile* getTilePtr() override;
        ~Merchant();
};


#endif

#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include <string>

using namespace std;

class Potion : public Item {
    public:
        Potion(string description, int x, int y, int id);
        virtual Tile* getTilePtr() = 0;
        virtual bool canPlayerUse(Player* player) override;
        virtual ~Potion();
};

#endif

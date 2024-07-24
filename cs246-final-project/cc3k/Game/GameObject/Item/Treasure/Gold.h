#ifndef GOLD_H
#define GOLD_H

#include "Item.h"
#include <string>

using namespace std;

class Gold : public Item {
    protected:
        int value;
    public:
        Gold(int value, string description, int x, int y, int id);
        virtual Tile* getTilePtr() override;
        int getValue();
        virtual bool canPlayerPickup(Player* player) override;
        virtual ~Gold();
};

#endif

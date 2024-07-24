#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"
#include <string>

using namespace std;

class Item : public GameObject {
    protected:
        string description;
    public:
        Item(string description, int x, int y, int id);

        // Gets the description of the item
        virtual string getDescription();

        // Returns whether a player can use an item.
        // Default: false
        virtual bool canPlayerUse(Player* player);

        // Returns whether a player can pick up an item.
        // Default: false
        virtual bool canPlayerPickup(Player* player);
        
        virtual ~Item() = default;
};

#endif

#ifndef ITEM_H
#define ITEM_H

#include "../GameObject.h"
#include "../../tileIDs.h"
#include <string>

using namespace std;

class Item : public GameObject {
    protected:
        string description;
    public:
        Item(string description, int x, int y, int id, int tile_type = NOTYPE);

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

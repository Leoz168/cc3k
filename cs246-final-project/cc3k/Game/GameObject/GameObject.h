#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Tile.h"
#include "../tileIDs.h"

class GameObject : public Tile {
    public:
        GameObject(int x, int y, int id, int room_number = NOASSOCIATEDROOM, int tile_type = NOTYPE);
        virtual ~GameObject() = default;
};

#endif

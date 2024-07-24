#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Tile.h"

class GameObject : public Tile {
    public:
        GameObject(int x, int y, int id);
        virtual ~GameObject() = default;
};

#endif

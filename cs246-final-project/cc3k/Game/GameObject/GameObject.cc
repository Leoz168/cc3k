#include "GameObject.h"
GameObject::GameObject(int x, int y, int id, int room_number = NOASSOCIATEDROOM, int tile_type): Tile{x, y, id, room_number, tile_type} {}

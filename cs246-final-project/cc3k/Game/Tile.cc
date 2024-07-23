#include "Tile.h"

Tile::Tile(int x, int y, int id) : x{x}, y{y}, id{id} {}
int Tile::getTileID() { return id; }
bool Tile::move(int dx, int dy) { return false; }
std::pair<bool, bool> Tile::playerAttack() { 
    return std::pair<bool, bool>{false, false};
}
bool Tile::playerUsed() { return false; }
bool Tile::takeAction() { return false; }

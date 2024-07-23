#include "Tile.h"

Tile::Tile(int x, int y, int id) : x{x}, y{y}, id{id} {}
int Tile::getTileID() { return id; }
bool Tile::move(int dx, int dy, Map& map) { return false; }
bool Tile::takeAction(Player*, Map& map) { return false; }
std::pair<int, int> Tile::getPosn() { return std::pair<int, int>{x, y}; }

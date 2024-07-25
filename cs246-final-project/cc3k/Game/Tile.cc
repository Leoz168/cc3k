#include "Tile.h"

Tile::Tile(int x, int y, int id, int room_number) : x{x}, y{y}, id{id}, room_number{room_number} {}
int Tile::getTileID() { return id; }
int Tile::getRoomNumber() { return room_number; }
bool Tile::move(int dx, int dy, GameMap& map) { return false; }
bool Tile::takeAction(Player*, GameMap& map) { return false; }
std::pair<int, int> Tile::getPosn() { return std::pair<int, int>{x, y}; }

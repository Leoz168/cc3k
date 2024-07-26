#include "Tile.h"

Tile::Tile(int x, int y, int id, int room_number, int tile_type) : x{x}, y{y}, id{id}, room_number{room_number}, tile_type{tile_type} {}
int Tile::getTileID() { return id; }
int Tile::getTileType() { return tile_type; }
int Tile::getRoomNumber() { return room_number; }
bool Tile::move(int dx, int dy, GameMap& map) { return false; }
bool Tile::takeAction(Player*, GameMap& map) { return false; }
std::pair<int, int> Tile::getPosn() { return std::pair<int, int>{x, y}; }

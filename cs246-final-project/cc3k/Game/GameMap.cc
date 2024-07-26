#include "GameMap.h"
#include "tileIDs.h"

using namespace std;

// Default initialize an empty map
explicit GameMap::GameMap() {}

// todo
GameMap::GameMap(string filename) {}

Tile* GameMap::tileAt(int x, int y) {
    vector<shared_ptr<Tile>> tile_vector = game_map[make_pair(x, y)];
    if (tile_vector.empty()) return nullptr;
    else return (tile_vector.back())->getTilePtr();
}

int GameMap::tileIDAt(int x, int y) {
    Tile* tileAtPosn = tileAt(x, y);
    if (tileAtPosn == nullptr) return NOTHING;
    else return tileAtPosn->getTileID();
}

int GameMap::typeTypeAt(int x, int y) {
    Tile* tileAtPosn = tileAt(x, y);
    if (tileAtPosn == nullptr) return NOTHING;
    else return tileAtPosn->getTileType();
}

bool GameMap::moveTile(int x, int y, int dx, int dy, Tile* tile) {
    vector<shared_ptr<Tile>> tile_vector = game_map[make_pair(x, y)];
    if (tile_vector.empty()) return false;
    else {
        for (shared_ptr<Tile> t : tile_vector) {
            if (t.get() == tile) {
                addTile(x+dx, y+dy, removeTile(x, y));
                return true;
            }
        }
    }
    return false;
}

shared_ptr<Tile> GameMap::removeTile(int x, int y) {
    vector<shared_ptr<Tile>>& tile_vector = game_map[make_pair(x, y)];
    if (tile_vector.empty()) return shared_ptr<Tile>{nullptr};
    else {
        shared_ptr<Tile> tilePtr = tile_vector.back();
        tile_vector.pop_back();
        return tilePtr;
    }
}

bool GameMap::addTile(int x, int y, shared_ptr<Tile> new_tile) {
    vector<shared_ptr<Tile>>& tile_vector = game_map[make_pair(x, y)];
    bool return_val = false;
    if (tile_vector.empty()) return_val = true;
    tile_vector.emplace_back(new_tile);

    if (new_tile->getTileID() == FLOORTILE) {
        int floortile_room_number = new_tile->getRoomNumber();
        if (floortile_room_number != NOASSOCIATEDROOM) {
            addFloorTileCoordToRoomMap(floortile_room_number, new_tile->getPosn());
        }
    }

    return return_val;
}

map<int, vector<pair<int, int>>>& GameMap::getRoomMapping() {
    return room_floortile_coord_mapping;
}


int GameMap::getNumRooms() {
    return num_rooms;
}

int GameMap::setNumRooms(int num) {
    num_rooms = num;
}

int GameMap::addRoom() {
    num_rooms++;
}

bool GameMap::addFloorTileCoordToRoomMap(int room_number, pair<int, int> coord) {
    if (room_number >= num_rooms) return false;

    vector<pair<int, int>>& coords_at_room = room_floortile_coord_mapping[room_number];

    for (auto it : coords_at_room) {
        if (it.first == coord.first && it.second == coord.second) return false;
    }

    coords_at_room.emplace_back(coord);
    return true;
}

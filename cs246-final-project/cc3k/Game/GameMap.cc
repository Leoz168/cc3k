#include "GameMap.h"
#include "tileIDs.h"

using namespace std;

// Default initialize an empty map
explicit GameMap::GameMap() {}

// todo
GameMap::GameMap(string filename) {}

Tile* GameMap::tileAt(int x, int y) {
    vector<shared_ptr<Tile>> tile_vector = game_map[make_pair(x, y)];
    if (tile_vector.size() == 0) return nullptr;
    else return (tile_vector.back())->getTilePtr();
}

int GameMap::tileIDAt(int x, int y) {
    vector<shared_ptr<Tile>> tile_vector = game_map[make_pair(x, y)];
    if (tile_vector.size() == 0) return NOTHING;
    else return (tile_vector.back())->getTileID();
}

bool GameMap::moveTile(int x, int y, int dx, int dy, Tile* tile) {
    vector<shared_ptr<Tile>> tile_vector = game_map[make_pair(x, y)];
    if (tile_vector.size() == 0) return false;
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
    if (tile_vector.size() == 0) return shared_ptr<Tile>{nullptr};
    else {
        shared_ptr<Tile> tilePtr = tile_vector.back();
        tile_vector.pop_back();
        return tilePtr;
    }
}

bool GameMap::addTile(int x, int y, shared_ptr<Tile> new_tile) {
    vector<shared_ptr<Tile>>& tile_vector = game_map[make_pair(x, y)];
    bool return_val = false;
    if (tile_vector.size() == 0) return_val = true;
    tile_vector.emplace_back(new_tile);
    return return_val;
}
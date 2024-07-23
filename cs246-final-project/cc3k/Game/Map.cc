#include "Map.h"
#include "tileIDs.h"

using namespace std;

// Default initialize an empty map
explicit Map::Map() {}

// todo
Map::Map(string filename) {}

Tile* Map::tileAt(int x, int y) {
    vector<shared_ptr<Tile>> tileVector = gameMap[make_pair(x, y)];
    if (tileVector.size() == 0) return nullptr;
    else return (tileVector.back())->getTilePtr();
}

int Map::tileIDAt(int x, int y) {
    vector<shared_ptr<Tile>> tileVector = gameMap[make_pair(x, y)];
    if (tileVector.size() == 0) return NOTHING;
    else return (tileVector.back())->getTileID();
}

bool Map::moveTile(int x, int y, int dx, int dy) {
    vector<shared_ptr<Tile>> tileVector = gameMap[make_pair(x, y)];
    if (tileVector.size() == 0) return false;
    else {
        addTile(x+dx, y+dy, removeTile(x, y));
        return true;
    }
}

shared_ptr<Tile> Map::removeTile(int x, int y) {
    vector<shared_ptr<Tile>>& tileVector = gameMap[make_pair(x, y)];
    if (tileVector.size() == 0) return shared_ptr<Tile>{nullptr};
    else {
        shared_ptr<Tile> tilePtr = tileVector.back();
        tileVector.pop_back();
        return tilePtr;
    }
}

bool Map::addTile(int x, int y, shared_ptr<Tile> newTile) {
    vector<shared_ptr<Tile>>& tileVector = gameMap[make_pair(x, y)];
    bool returnVal = false;
    if (tileVector.size() == 0) returnVal = true;
    tileVector.emplace_back(newTile);
    return returnVal;
}

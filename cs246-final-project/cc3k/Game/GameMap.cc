#include "GameMap.h"
#include "tileIDs.h"

using namespace std;

// Default initialize an empty map
explicit GameMap::GameMap() {}

// todo
GameMap::GameMap(string filename) {}

Tile* GameMap::tileAt(int x, int y) {
    vector<shared_ptr<Tile>> tileVector = gameMap[make_pair(x, y)];
    if (tileVector.size() == 0) return nullptr;
    else return (tileVector.back())->getTilePtr();
}

int GameMap::tileIDAt(int x, int y) {
    vector<shared_ptr<Tile>> tileVector = gameMap[make_pair(x, y)];
    if (tileVector.size() == 0) return NOTHING;
    else return (tileVector.back())->getTileID();
}

bool GameMap::moveTile(int x, int y, int dx, int dy, Tile* tile) {
    vector<shared_ptr<Tile>> tileVector = gameMap[make_pair(x, y)];
    if (tileVector.size() == 0) return false;
    else {
        for (shared_ptr<Tile> t : tileVector) {
            if (t.get() == tile) {
                addTile(x+dx, y+dy, removeTile(x, y));
                return true;
            }
        }
    }
    return false;
}

shared_ptr<Tile> GameMap::removeTile(int x, int y) {
    vector<shared_ptr<Tile>>& tileVector = gameMap[make_pair(x, y)];
    if (tileVector.size() == 0) return shared_ptr<Tile>{nullptr};
    else {
        shared_ptr<Tile> tilePtr = tileVector.back();
        tileVector.pop_back();
        return tilePtr;
    }
}

bool GameMap::addTile(int x, int y, shared_ptr<Tile> newTile) {
    vector<shared_ptr<Tile>>& tileVector = gameMap[make_pair(x, y)];
    bool returnVal = false;
    if (tileVector.size() == 0) returnVal = true;
    tileVector.emplace_back(newTile);
    return returnVal;
}

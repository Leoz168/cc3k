#include "Cell.h"

using namespace std;

Cell::Cell(int x, int y) : Tile{x, y} {}
Tile* Cell::getTilePtr() { return this; }
bool Cell::move(int dx, int dy) { return false; }
pair<bool, bool> Cell::playerAttack() { 
    return std::pair<bool, bool>{false, false};
}
bool Cell::playerUsed() { return false; }
bool Cell::takeAction() { return false; }
Cell::~Cell() {}

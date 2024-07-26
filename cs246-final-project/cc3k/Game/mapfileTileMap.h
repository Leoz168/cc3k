#pragma once;

#include "tileIDs.h"
#include <map>

const std::map<char, int> cellMap {
    {' ', BLANK},
    {'.', FLOORTILE},
    {'|', VWALL},
    {'-', HWALL},
    {'#', PASSAGE},
    {'+', DOORWAY},
    {'\\', STAIR}
};

const std::map<char, int> itemMap {
    {'0', RESTOREHEALTH},
    {'1', BOOSTATK},
    {'2', BOOSTDEF},
    {'3', POISONHEALTH},
    {'4', WOUNDATK},
    {'5', WOUNDDEF},
    {'6', NORMALGOLD},
    {'7', SMALLGOLD},
    {'8', MERCHANTHOARD},
    {'9', DRAGONHOARD}
};
const std::map<char, int> enemyMap {
    {'D', DRAGON},
    {'H', HUMAN},
    {'E', ELF},
    {'O', ORC},
    {'L', HALFLING},
    {'M', MERCHANT},
    {'W', DWARF},
};

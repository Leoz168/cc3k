#ifndef TILEIDS
#define TILEIDS

enum TileID {
    NOTHING = -1,

    // Cells
    BLANK = 0,
    FLOORTILE,
    HWALL,
    VWALL,
    PASSAGE,
    DOORWAY,
    STAIR,

    // Treasure/Gold
    SMALLGOLD,
    NORMALGOLD,
    MERCHANTHOARD,
    DRAGONHOARD,

    // Potions
    RESTOREHEALTH,
    BOOSTATK,
    BOOSTDEF,
    POISONHEALTH,
    WOUNDATK,
    WOUNDDEF,

    // Enemies
    HUMAN,
    MERCHANT,
    DRAGON,
    HALFLING,
    ORC,
    ELF,
    DWARF,

    // Races
    SHADE,
    DROW,
    VAMPIRE,
    TROLL,
    GOBLIN
};

enum TileType {
    NOTYPE = -1,
    CELL = 0,
    TREASURE,
    POTION,
    ENEMY,
    PLAYER
};

#endif

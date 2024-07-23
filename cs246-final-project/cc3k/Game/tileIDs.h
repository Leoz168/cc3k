#ifndef TILEIDS
#define TILEIDS

enum tileID {
    // Cells
    BLANK = 0,
    FLOORTILE,
    HWALL,
    VWALL,
    PASSAGE,
    DOORWAY,
    STAIR,

    // Treasure/Gold
    GOLD,
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

#endif

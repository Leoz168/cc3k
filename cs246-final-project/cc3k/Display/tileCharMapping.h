#ifndef TILECHARMAPPING
#define TILECHARMAPPING

#include "../Game/tileIDs.h"
#include <iostream>
#include <map>

char IDToChar(int id) {
    switch (id)
    {
    case BLANK:
        return ' ';
        break;
    
    case FLOORTILE:
        return '.';
        break;

    case HWALL:
        return '-';
        break;

    case VWALL:
        return '|';
        break;

    case PASSAGE:
        return '#';
        break;

    case DOORWAY:
        return '+';
        break;

    case STAIR:
        return '\\';
        break;

    case SMALLGOLD:
        return 'G';
        break;

    case NORMALGOLD:
        return 'G';
        break;

    case MERCHANTHOARD:
        return 'G';
        break;

    case RESTOREHEALTH:
        return 'P';
        break;
    
    case BOOSTATK:
        return 'P';
        break;

    case BOOSTDEF:
        return 'P';
        break;

    case POISONHEALTH:
        return 'P';
        break;

    case WOUNDATK:
        return 'P';
        break;

    case WOUNDDEF:
        return 'P';
        break;

    case HUMAN:
        return 'H';
        break;

    case MERCHANT:
        return 'M';
        break;

    case DRAGON:
        return 'D';
        break;

    case HALFLING:
        return 'L';
        break;

    case ORC:
        return 'O';
        break;

    case ELF:
        return 'E';
        break;

    case DWARF:
        return 'W';
        break;

    case SHADE:
        return '@';
        break;

    case DROW:
        return '@';
        break;

    case VAMPIRE:
        return '@';
        break;

    case TROLL:
        return '@';
        break;

    case GOBLIN:
        return '@';
        break;

    default:
        std::cerr << "wtf you are getting" << std::endl;
        return ' ';
        break;
    }
}

#endif

#ifndef TILECHARMAPPING
#define TILECHARMAPPING

#include "../Game/tileIDs.h"
#include <iostream>
#include <map>
#include <string>

std::string RED = "\033[31m";
std::string GREEN = "\033[32m";
std::string BLUE = "\033[34m";
std::string YELLOW = "\033[33m";


string IDToChar(int id) {
    switch (id)
    {
    case BLANK:
        return " ";
        break;
    
    case FLOORTILE:
        return ".";
        break;

    case HWALL:
        return "-";
        break;

    case VWALL:
        return "|";
        break;

    case PASSAGE:
        return "#";
        break;

    case DOORWAY:
        return "+";
        break;

    case STAIR:
        return BLUE + "\\" + "\033[0m";
        break;

    case SMALLGOLD:
        return YELLOW + "G" + "\033[0m";
        break;

    case NORMALGOLD:
        return YELLOW + "G" + "\033[0m";
        break;

    case MERCHANTHOARD:
        return YELLOW + "G" + "\033[0m";
        break;

    case DRAGONHOARD:
        return YELLOW + "G" + "\033[0m";
        break;

    case RESTOREHEALTH:
        return GREEN + "P" + "\033[0m";
        break;
    
    case BOOSTATK:
        return GREEN + "P" + "\033[0m";
        break;

    case BOOSTDEF:
        return GREEN + "P" + "\033[0m";
        break;

    case POISONHEALTH:
        return GREEN + "P" + "\033[0m";
        break;

    case WOUNDATK:
        return GREEN + "P" + "\033[0m";
        break;

    case WOUNDDEF:
        return GREEN + "P" + "\033[0m";
        break;

    case HUMAN:
        return RED + "H" + "\033[0m";
        break;

    case MERCHANT:
        return RED + "M" + "\033[0m";
        break;

    case DRAGON:
        return RED + "D" + "\033[0m";
        break;

    case HALFLING:
        return RED + "L" + "\033[0m";
        break;

    case ORC:
        return RED + "O" + "\033[0m";
        break;

    case ELF:
        return RED + "E" + "\033[0m";
        break;

    case DWARF:
        return RED + "W" + "\033[0m";
        break;

    case SHADE:
        return BLUE + "@" + "\033[0m";
        break;

    case DROW:
        return BLUE + "@" + "\033[0m";
        break;

    case VAMPIRE:
        return BLUE + "@" + "\033[0m";
        break;

    case TROLL:
        return BLUE + "@" + "\033[0m";
        break;

    case GOBLIN:
        return BLUE + "@" + "\033[0m";
        break;

    default:
        std::cerr << "wtf you are getting" << std::endl;
        return " ";
        break;
    }
}

#endif

#include "InfoDisplay.h"
#include <iostream>
#include <iomanip>
#include <string>

InfoDisplay::InfoDisplay(GameModel* gameSubject) : gm{gameSubject} {
    gm->attach(this);
}

string idToRace(int id) {
    switch (id)
    {
    case SHADE:
        return "Shade";
        break;

    case DROW:
        return "Drow";
        break;

    case VAMPIRE:
        return "Vampire";
        break;

    case TROLL:
        return "Troll";
        break;

    case GOBLIN:
        return "Goblin";
        break;
    
    default:
        return "Idk what you are";
        break;
    }
}

void InfoDisplay::notify() {
    cout << setfill(' ');
        cout << left << "Race: " << idToRace(gm->getPlayerRace()) << " Gold: " << gm->getGold();
        cout << right << setw(55) << "Floor: " << gm->getFloor() << endl;
        cout << "HP: " << setw(4) << gm->getHP() << endl;
        cout << "Atk: " << setw(3) << gm->getAtk() << endl;
        cout << "Def: " << setw(3) << gm->getdef() << endl;
        cout << "Action: " << gm->getStatusMessage() << endl;
}

InfoDisplay::~InfoDisplay() {
    gm->detach(this);
}

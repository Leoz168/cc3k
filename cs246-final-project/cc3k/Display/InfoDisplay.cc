#include "InfoDisplay.h"
#include <iostream>
#include <iomanip>

InfoDisplay::InfoDisplay(GameModel* gameSubject) : gm{gameSubject} {
    gm->attach(this);
}

void InfoDisplay::notify() {
    cout << setfill(' ');
        cout << left << "Race: " << gm->getPlayerRace() << " Gold: " << gm->getGold();
        cout << right << setw(55) << "Floor: " << gm->getFloor() << endl;
        cout << "HP: " << setw(4) << gm->getHP() << endl;
        cout << "Atk: " << setw(3) << gm->getAtk() << endl;
        cout << "Def: " << setw(3) << gm->getdef() << endl;
        cout << "Action: " << gm->getStatusMessage() << endl;
}

InfoDisplay::~InfoDisplay() {
    gm->detach(this);
}

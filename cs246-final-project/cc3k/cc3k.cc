#include <iostream>

#include "Display/observer.h"
#include "Game/GameSubject.h"

using namespace std;


int main() {
    char mode;
    cin >> mode;
    switch (mode)
    while (true) { // choose the race
        {
        case 's': // shade
            /* code */
            break;

        case 'd': // drow
            /* code */
            break;

        case 'v': // vampire
            /* code */
            break;

        case 'g': // goblin
            /* code */
            break;
    
        case 't': // troll
            /* code */
            break;
        }
    }
    string command;
    while (true) {
        cin >> command;
        if (cin.fail() && !cin.eof()) {
            cin.clear();
            cin.ignore();
            continue;
        }
        // game loop
    }


}

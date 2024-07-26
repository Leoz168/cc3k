#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Display/observer.h"
#include "Game/GameModel.h"
#include "Display/GameSubject.h"

using namespace std;

enum class PlayerCommand {NO, SO, EA, WE, NE, NW, SE, SW, U, A, F, R, Q, NONE};

int main(int argc, char* argv[]) {
    // srand(time(NULL));
    srand((unsigned int)time(0));
    GameModel gm;
    gm.startGame();
    while (true) {
        string command;
        string filename;
        int i = 0;
        if (argc == 2) {
            while (argv[1][i]) {
                filename += argv[1][i];       // read arg into fileName
                ++i;
            }
            ifstream fs {filename};
            gm.initializeMap(fs, true);
        }

        while (true) {
            char race;
            cin >> race;
            switch (race)
            {
            case 's':
                gm.createPlayerAtRandPosn(race);
                break;

            case 'd':
                gm.createPlayerAtRandPosn(race);
                break;

            case 'v':
                gm.createPlayerAtRandPosn(race);
                break;

            case 'g':
                gm.createPlayerAtRandPosn(race);
                break;

            case 't':
                gm.createPlayerAtRandPosn(race);
                break;

            case 'f':
                gm.freezeEnemy();
                while (true) {
                    char is_refreeze;
                    cin >> is_refreeze;
                    if (is_refreeze == 'f') {
                        gm.unfreezeEnemy();
                        break;
                    }
                }
                break;

            case 'r':
                gm.restartGame();
                continue;
            
            default:
                cout << "Invalid input" << endl;
                break;
            }
        }

        if (cin.fail() && !cin.eof()) {
            cin.clear();
            cin.ignore();
            continue;
        }
        // game loop
    }


}

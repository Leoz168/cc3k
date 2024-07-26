#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "observer.h"
#include "GameModel.h"
#include "GameSubject.h"

using namespace std;

enum class PlayerCommand {NO, SO, EA, WE, NE, NW, SE, SW, U, A, F, R, Q, NONE};

PlayerCommand processCommand(const string& command) {
    PlayerCommand enumCom;

    if (command == "no") enumCom = PlayerCommand::NO;
    else if (command == "so") enumCom = PlayerCommand::SO;
    else if (command == "ea") enumCom = PlayerCommand::EA;
    else if (command == "we") enumCom = PlayerCommand::WE;
    else if (command == "ne") enumCom = PlayerCommand::NE;
    else if (command == "nw") enumCom = PlayerCommand::NW;
    else if (command == "se") enumCom = PlayerCommand::SE;
    else if (command == "sw") enumCom = PlayerCommand::SW;
    else if (command == "u") enumCom = PlayerCommand::U;
    else if (command == "a") enumCom = PlayerCommand::A;
    else if (command == "f") enumCom = PlayerCommand::F;
    else if (command == "r") enumCom = PlayerCommand::R;
    else if (command == "q") enumCom = PlayerCommand::Q;
    else enumCom = PlayerCommand::NONE;

    return enumCom;
}

int main(int argc, char* argv[]) {
    // srand(time(NULL));
    srand((unsigned int)time(0));
    GameModel gm;
    gm.startGame();
    while (true) {
        string command;
        string filename = "";
        int i = 0;
        if (argc == 2) {
            while (argv[1][i]) {
                filename += argv[1][i];       // read arg into fileName
                ++i;
            }
        }
        ifstream ifs_map {filename};
        // handle race
        while (true) {
            char race;
            cin >> race;
            switch (race) {
            case 's':
                gm.setPlayerRace(race);
                if (filename == "") gm.initializeMap(ifs_map, false);
                else gm.initializeMap(ifs_map, true);
                break;
            case 'd':
                gm.setPlayerRace(race);
                if (filename == "") gm.initializeMap(ifs_map, false);
                else gm.initializeMap(ifs_map, true);
                break;
            case 'v':
                gm.setPlayerRace(race);
                if (filename == "") gm.initializeMap(ifs_map, false);
                else gm.initializeMap(ifs_map, true);
                break;
            case 'g':
                gm.setPlayerRace(race);
                if (filename == "") gm.initializeMap(ifs_map, false);
                else gm.initializeMap(ifs_map, true);
                break;
            case 't':
                gm.setPlayerRace(race);
                if (filename == "") gm.initializeMap(ifs_map, false);
                else gm.initializeMap(ifs_map, true);
                break;
            case 'f':
                gm.freezeEnemy();
                while (true) {
                    char is_refreeze;
                    cin >> is_refreeze;
                    if (cin.fail() && !cin.eof()) {
                        cin.ignore();
                        cin.clear();
                    }
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
                continue;
            }

            while (true) {
                cin >> command;
                switch (processCommand(command))
                {
                case PlayerCommand::NO:
                    gm.moveEnemy(command);
                    gm.updateGame();
                    break;

                case PlayerCommand::SO:
                    gm.moveEnemy(command);
                    gm.updateGame();
                    break;
                
                case PlayerCommand::EA:
                    gm.moveEnemy(command);
                    gm.updateGame();
                    break;
                
                case PlayerCommand::WE:
                    gm.moveEnemy(command);
                    gm.updateGame();
                    break;

                case PlayerCommand::NE:
                    gm.moveEnemy(command);
                    gm.updateGame();
                    break;

                case PlayerCommand::NW:
                    gm.moveEnemy(command);
                    gm.updateGame();
                    break;

                case PlayerCommand::SE:
                    gm.moveEnemy(command);
                    gm.updateGame();
                    break;

                case PlayerCommand::SW:
                    gm.moveEnemy(command);
                    gm.updateGame();
                    break;

                case PlayerCommand::U:
                {
                    cin >> command;
                    PlayerCommand direction = processCommand(command);

                    switch (direction) {                            // use potion in direction
                    case PlayerCommand::NO:
                        gm.usePotion(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::SO:
                        gm.usePotion(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::EA:
                        gm.usePotion(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::WE:
                        gm.usePotion(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::NE:
                        gm.usePotion(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::NW:
                        gm.usePotion(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::SE:
                        gm.usePotion(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::SW:
                        gm.usePotion(command);
                        gm.updateGame();
                        break;

                    default:
                        cout << "Ooops... U cannot throw it this way..." << endl;
                        break;
                    }
                    break;
                }

                case PlayerCommand::A:
                {
                    cin >> command;
                    PlayerCommand direction = processCommand(command);

                    switch (direction) {                            // use potion in direction
                    case PlayerCommand::NO:
                        gm.playerAttack(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::SO:
                        gm.playerAttack(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::EA:
                        gm.playerAttack(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::WE:
                        gm.playerAttack(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::NE:
                        gm.playerAttack(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::NW:
                        gm.playerAttack(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::SE:
                        gm.playerAttack(command);
                        gm.updateGame();
                        break;

                    case PlayerCommand::SW:
                        gm.playerAttack(command);
                        gm.updateGame();
                        break;

                    default:
                        cout << "Ewwww... U missed xD" << endl;
                        break;
                    }
                    break;
                }

                default:
                    cout << "BOOM! U cannot break the wall. U're restricted in 2D universe" << endl;
                    break;
                }
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

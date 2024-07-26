#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Display/observer.h"
#include "Game/GameModel.h"
#include "Display/GameSubject.h"
#include "Game/Directions.h"

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

Directions commandToDirection(const PlayerCommand command) {
    switch (command){
        case PlayerCommand::NO:
            return Directions::N;
        case PlayerCommand::NE:
            return Directions::NE;
        case PlayerCommand::EA:
            return Directions::E;
        case PlayerCommand::SE:
            return Directions::SE;
        case PlayerCommand::SO:
            return Directions::S;
        case PlayerCommand::SW:
            return Directions::SW;
        case PlayerCommand::WE:
            return Directions::W;
        case PlayerCommand::NW:
            return Directions::NW;
        default:
            cerr << "invalid command for commandToDirection" << endl;
            return Directions::N;
    }
}

int main(int argc, char* argv[]) {
    cout << "Welcome to CC3K. Enter one of supported commands: " << endl;
    cout << "s: selects SHADE race." << endl;
    cout << "d: selects DROW race." << endl;
    cout << "g: selects GOBLIN race." << endl;
    cout << "t: selects TROLL race." << endl;
    cout << "v: selects VAMPIRE race." << endl;
    cout << "f: freeze ALL enemies, until f is pressed again." << endl;
    cout << "r: RESTART the game." << endl;
    cout << "q: QUIT the game." << endl;
    cout << "" << endl;
    cout << "After selecting the race, use the following commands:" << endl;
    cout << "no,so,ea,we,ne,nw,se,sw: moves the player character one block in the appropriate cardinal direction." << endl;
    cout << "u direction: uses the potion indicated by the direction." << endl;
    cout << "a direction: attacks the enemy in the specified direction." << endl;

    cout << endl;

    const string emptyFloorFile = "emptyfloor.txt";

    // srand(time(NULL));
    srand((unsigned int)time(0));
    string filename = "";
    if (argc == 2) {
        filename = argv[1];
    } else {
        filename = emptyFloorFile;
    }
    GameModel gm{filename == emptyFloorFile ? false : true, filename};

    while (true) {
        string command;
        ifstream ifs_map {filename};
        // handle race
        bool race_selection = true;
        while (race_selection) {
            cout << "Please select a race: (s, d, v, g, t)" << endl;
            char race;
            if (!(cin >> race)) {
                return 0;
            }
            race_selection = false;
            switch (std::tolower(race)) {
                case 's':
                    gm.setPlayerRace(race);
                    if (filename == emptyFloorFile) gm.initializeMap(ifs_map, false);
                    else gm.initializeMap(ifs_map, true);
                    break;
                case 'd':
                    gm.setPlayerRace(race);
                    if (filename == emptyFloorFile) gm.initializeMap(ifs_map, false);
                    else gm.initializeMap(ifs_map, true);
                    break;
                case 'v':
                    gm.setPlayerRace(race);
                    if (filename == emptyFloorFile) gm.initializeMap(ifs_map, false);
                    else gm.initializeMap(ifs_map, true);
                    break;
                case 'g':
                    gm.setPlayerRace(race);
                    if (filename == emptyFloorFile) gm.initializeMap(ifs_map, false);
                    else gm.initializeMap(ifs_map, true);
                    break;
                case 't':
                    gm.setPlayerRace(race);
                    if (filename == emptyFloorFile) gm.initializeMap(ifs_map, false);
                    else gm.initializeMap(ifs_map, true);
                    break;
                default:
                    cout << "Oops! Invalid race selection." << endl;
                    race_selection = true;
            }
        }

        gm.startGame();
        bool gameRunning = true;

        while (gameRunning) {
            if (!(cin >> command)) {
                gm.endGame(false);
            }

            switch (processCommand(command)) {
                case PlayerCommand::NO:
                    gm.movePlayer(commandToDirection(processCommand(command)));
                    gm.updateGame();
                    break;

                case PlayerCommand::SO:
                    gm.movePlayer(commandToDirection(processCommand(command)));
                    gm.updateGame();
                    break;
                
                case PlayerCommand::EA:
                    gm.movePlayer(commandToDirection(processCommand(command)));
                    gm.updateGame();
                    break;
                
                case PlayerCommand::WE:
                    gm.movePlayer(commandToDirection(processCommand(command)));
                    gm.updateGame();
                    break;

                case PlayerCommand::NE:
                    gm.movePlayer(commandToDirection(processCommand(command)));
                    gm.updateGame();
                    break;

                case PlayerCommand::NW:
                    gm.movePlayer(commandToDirection(processCommand(command)));
                    gm.updateGame();
                    break;

                case PlayerCommand::SE:
                    gm.movePlayer(commandToDirection(processCommand(command)));
                    gm.updateGame();
                    break;

                case PlayerCommand::SW:
                    gm.movePlayer(commandToDirection(processCommand(command)));
                    gm.updateGame();
                    break;

                case PlayerCommand::U: {
                    if (!(cin >> command)) {
                        gm.endGame(false);
                    }
                    PlayerCommand direction = processCommand(command);
                    switch (direction) {                            // use potion in direction
                        case PlayerCommand::NO:
                            gm.usePotion(commandToDirection(processCommand(command)));
                            gm.updateGame();
                            break;

                        case PlayerCommand::SO:
                            gm.usePotion(commandToDirection(processCommand(command)));
                            gm.updateGame();
                            break;

                        case PlayerCommand::EA:
                            gm.usePotion(commandToDirection(processCommand(command)));
                            gm.updateGame();
                            break;

                        case PlayerCommand::WE:
                            gm.usePotion(commandToDirection(processCommand(command)));
                            gm.updateGame();
                            break;

                        case PlayerCommand::NE:
                            gm.usePotion(commandToDirection(processCommand(command)));
                            gm.updateGame();
                            break;

                        case PlayerCommand::NW:
                            gm.usePotion(commandToDirection(processCommand(command)));
                            gm.updateGame();
                            break;

                        case PlayerCommand::SE:
                            gm.usePotion(commandToDirection(processCommand(command)));
                            gm.updateGame();
                            break;

                        case PlayerCommand::SW:
                            gm.usePotion(commandToDirection(processCommand(command)));
                            gm.updateGame();
                            break;

                        default:
                            cout << "Ooops... U cannot throw it this way..." << endl;
                            break;
                    }
                    break;
                }
                case PlayerCommand::A: {
                    if (!(cin >> command)) {
                        gm.endGame(false);
                    }
                    PlayerCommand direction = processCommand(command);

                    switch (direction) {                            // use potion in direction
                    case PlayerCommand::NO:
                        gm.playerAttack(commandToDirection(processCommand(command)));
                        gm.updateGame();
                        break;

                    case PlayerCommand::SO:
                        gm.playerAttack(commandToDirection(processCommand(command)));
                        gm.updateGame();
                        break;

                    case PlayerCommand::EA:
                        gm.playerAttack(commandToDirection(processCommand(command)));
                        gm.updateGame();
                        break;

                    case PlayerCommand::WE:
                        gm.playerAttack(commandToDirection(processCommand(command)));
                        gm.updateGame();
                        break;

                    case PlayerCommand::NE:
                        gm.playerAttack(commandToDirection(processCommand(command)));
                        gm.updateGame();
                        break;

                    case PlayerCommand::NW:
                        gm.playerAttack(commandToDirection(processCommand(command)));
                        gm.updateGame();
                        break;

                    case PlayerCommand::SE:
                        gm.playerAttack(commandToDirection(processCommand(command)));
                        gm.updateGame();
                        break;

                    case PlayerCommand::SW:
                        gm.playerAttack(commandToDirection(processCommand(command)));
                        gm.updateGame();
                        break;

                    default:
                        cout << "Ewwww... U missed xD" << endl;
                        break;
                    }
                    break;
                }
                case PlayerCommand::F:
                    if (gm.isEnemyFrozen()) gm.unfreezeEnemy();
                    else gm.freezeEnemy();
                    break;
                case PlayerCommand::R:
                    gm.endGame(false);
                    gameRunning = false;
                    break;
                case PlayerCommand::Q:
                    gm.endGame(false);
                    return 0;
                default:
                    cout << "BOOM! U cannot break the wall. U're restricted in 2D universe" << endl;
                    break;
            }
        }
    }
        // game loop
}

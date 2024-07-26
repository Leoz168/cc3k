#include "GameModel.h"
#include "mapfileTileMap.h"
#include <regex>
#include <algorithm>
#include <iostream>
using namespace std;

GameModel::GameModel(bool isMapProvided, string mapFile) : 
    isMapProvided{isMapProvided}, 
    mapFile{mapFile} {}

void GameModel::setPlayerRace(char type){
    int id = playerRaceMap.at(type);
    playerRace = id;
}

// Get the ID of the tile at the given coordinates
int GameModel::tileIDAt(int x, int y) {
    return gameMap.tileIDAt(x, y);
}

bool GameModel::isAvailableTileForSpawn(int x, int y) {
    int id = gameMap.tileIDAt(x, y);
    if (id == FLOORTILE || id == BLANK) {
        return true;
    }
    return false;
}

int GameModel::getCols() {
    return numCols;
}

int GameModel::getRows() {
    return numRows;
}

int GameModel::getPlayerRace() {
    return player->getTileID();
}

int GameModel::getGold() {
    return player->getGoldCount();
}

int GameModel::getFloor() {
    return floorLevel;
}

int GameModel::getHP() {
    return player->getHP();
}

int GameModel::getAtk() {
    return player->getAtk();
}

int GameModel::getdef() {
    return player->getDef();
}

std::pair<int, int> GameModel::findAvailableTileAround(int x, int y) {
    std::pair<int, int> firstAvailableTile = std::make_pair(0, 0);
    if (isAvailableTileForSpawn(x + 1, y)) {
        firstAvailableTile.first = x + 1;
        firstAvailableTile.second = y;
    } else if (isAvailableTileForSpawn(x - 1, y)) {
        firstAvailableTile.first = x - 1;
        firstAvailableTile.second = y;
    } else if (isAvailableTileForSpawn(x, y + 1)) {
        firstAvailableTile.first = x;
        firstAvailableTile.second = y + 1;
    } else if (isAvailableTileForSpawn(x, y - 1)) {
        firstAvailableTile.first = x;
        firstAvailableTile.second = y - 1;
    } else if (isAvailableTileForSpawn(x + 1, y + 1)) {
        firstAvailableTile.first = x + 1;
        firstAvailableTile.second = y + 1;
    } else if (isAvailableTileForSpawn(x + 1, y - 1)) {
        firstAvailableTile.first = x + 1;
        firstAvailableTile.second = y - 1;
    } else if (isAvailableTileForSpawn(x - 1, y + 1)) {
        firstAvailableTile.first = x - 1;
        firstAvailableTile.second = y + 1;
    } else if (isAvailableTileForSpawn(x - 1, y - 1)) {
        firstAvailableTile.first = x - 1;
        firstAvailableTile.second = y - 1;
    } else {
        cerr << "Inside findAvailableTileAround(). Cannot find available tile for position: " + std::to_string(x) + " " + std::to_string(y) << endl;
    }
    return firstAvailableTile;
}

// Initialize the map
void GameModel::initializeMap(ifstream &mapFile, bool isMapProvided) {
    // Initialize the map from a file:
    if (!isMapProvided) {
        readMap(mapFile, isMapProvided);
        createPlayerAtRandPosn();
        createStairAtRandPosn();
        createPotionAtRandPosn();
        createGoldAtRandPosn();
        createEnemyAtRandPosn();
        createDragonAndHoardAtRandPosn();
    } else {
        readMap(mapFile, isMapProvided);
    }
}


bool isFloodfillValid(char type) {
    return (type == '.' || type == '\\' || type == playerChar || itemMap.count(type) || enemyMap.count(type));
}


void floodfillInit(GameModel* model, int x, int y, vector<string>& floor_lines, vector<vector<bool>>& tiles_processed, int room_number) {
    tiles_processed[y][x] = true;
    
    char type = floor_lines[y][x];
    if (type != '.') model->spawnObject(x, y, '.', room_number);
    model->spawnObject(x, y, type, room_number);

    for (auto it : DIRECTIONS_POSN_CHANGE) {
        int newx = x + it.second.first;
        int newy = y + it.second.second;
        if (newx >= 0 && newy >= 0 
            && newy < floor_lines.size() 
            && newx < floor_lines[newy].length()
            && tiles_processed[newy][newx] == false
            && isFloodfillValid(floor_lines[newy][newx])) {
                floodfillInit(model, newx, newy, floor_lines, tiles_processed, room_number);
            }
    }
}


// Read the map from the file: either provided one or emptyfloor.txt
// NOTE: for floors from a file, floorLevel MUST represent the floor to generate.
void GameModel::readMap(std::ifstream &mapFile, bool isMapProvided) {
    string line;
    int y = 0; // Line number
    int max_col_size = 0;

    const regex horizontal_border{"\\|-*\\|\\n*"};

    if (isMapProvided) {
        for (int i = 1; i < floorLevel; i++) {
            int borders = 0;
            while (getline(mapFile, line) && borders < 2) {
                if (regex_match(line, horizontal_border)) borders++;
            }
        }
    }

    vector<string> floor_lines;
    vector<vector<bool>> tiles_processed;

    int borders = 0;
    while (getline(mapFile, line) && borders < 2) {
        int line_size = line.length();
        if (line_size > max_col_size) max_col_size = line_size;

        std::vector<bool> line_processed;
        for (int i = 0; i < line_size; i++) {
            line_processed.emplace_back(false);
        }

        if (regex_match(line, horizontal_border)) borders++;

        floor_lines.emplace_back(move(line));

        tiles_processed.emplace_back(move(line_processed));
    }

    int room_number = 0;

    for (int y = 0; y < floor_lines.size(); ++y) {
        string& floor_line = floor_lines[y];
        for (int x = 0; x < floor_line.size(); ++x) {
            if (tiles_processed[y][x] == false) {
                char type = floor_line[x];
                tiles_processed[y][x] = true;
                if (isFloodfillValid(type)) {
                    floodfillInit(this, x, y, floor_lines, tiles_processed, room_number);
                    room_number++;
                } else {
                    spawnObject(x, y, type);
                }
            }
        }
    }

    numRows = floor_lines.size();
    numCols = max_col_size;
    gameMap.setMapSize(numRows, numCols);
}

// Spawn a specific type of game object and add it to the gameMap
void GameModel::spawnObject(int x, int y, char type, int room_number) {
    CellCreator makeCell;
    EnemyCreator makeEnemy;
    ItemCreator makeItem;
    PlayerCreator makePlayer;
    FloorTileCreator makeFloorTile;
    std::shared_ptr<Tile> newObject;
    std::shared_ptr<Player> newPlayer;
    int id = NOTHING;
    bool floorCreated = false;
    bool playerCreated = false;

    if (type == playerChar) { // Input char is player
        if (isPlayerCreated == false) {
            newPlayer = makePlayer.spawnPlayer(x, y, playerRace);
            player = newPlayer; // initialize the player
            isPlayerCreated = true;
        } else {
            newPlayer = player;
            player->setPosition(x, y);
        }
        playerCreated = true;
    } else if (cellMap.count(type)) { // Input char is a cell
        id = cellMap.at(type);

        if (id == FLOORTILE) {
            newObject = makeFloorTile.spawnFloorTile(x, y, room_number);
        } else {
            newObject = makeCell.spawnTile(x, y, id, false);
            if (id == STAIR) {
                isStairCreated = true;
                stair = newObject;
            }
        }

        cells.emplace_back(move(dynamic_pointer_cast<Cell>(newObject))); // add to cell vector

    } else if (itemMap.count(type)) { // Input char is an Item
        id = itemMap.at(type);

        if (!isDragonHoardCreated && id == DRAGONHOARD) { // init dragon hoard separately
            dragonHoardPosn = std::make_pair(x, y);
            dragonHoard = std::make_shared<DragonHoard>(x, y, true);
            isDragonHoardCreated = true;
            items.emplace_back(dragonHoard);
            gameMap.addTile(x, y, dragonHoard);
            return;
        }

        newObject = makeItem.spawnTile(x, y, id, false);
        items.emplace_back(move(dynamic_pointer_cast<Item>(newObject)));

    } else if (enemyMap.count(type)) { // Input char is an Enemy
        id = enemyMap.at(type);

        if (!isDragonCreated && id == DRAGON) { //init dragon separately
            if (isDragonHoardCreated) { // dragonHoard already exists -> just init Dragon
                isDragonCreated = true;
                dragon = std::make_shared<Dragon>(x, y, dragonHoard);
                enemies.emplace_back(dragon);
                gameMap.addTile(x, y, dragon);

            } else { // dragonHoard does not yet exist -> store dragon posn into a pair
                dragonPosn = std::make_pair(x, y);
                isDragonCreated = false; // dragon not yet created
            }
            return;
        }

        newObject = makeEnemy.spawnTile(x, y, id, false);
        enemies.emplace_back(move(dynamic_pointer_cast<Enemy>(newObject))); // add to enemies vector

    } else {
        std::cerr << "Reached default. Invalid input " + std::to_string(type) + "type in spawnObject class" << endl;
        return;
    }

    // Add newObject to gameMap:
    if (playerCreated) gameMap.addTile(x, y, newPlayer);
    else gameMap.addTile(x, y, newObject);
}

// Spawn a random game object(Item or Enemy) and add it to the gameMap
void GameModel::spawnRandObject(int x, int y, char type) {
    CellCreator makeCell;
    EnemyCreator makeEnemy;
    ItemCreator makeItem;
    std::shared_ptr<Tile> newObject;

    switch (type) {
        case 'E':
            newObject = makeEnemy.spawnTile(x, y, HUMAN, true); // default value for id
            enemies.emplace_back(move(dynamic_pointer_cast<Enemy>(newObject)));
            break;

        case 'G':
            newObject = makeItem.spawnTile(x, y, NORMALGOLD, true); // default value for id
            items.emplace_back(move(dynamic_pointer_cast<Item>(newObject)));
            break;

        case 'P':
            newObject = makeItem.spawnTile(x, y, RESTOREHEALTH, true); // default value for id
            items.emplace_back(move(dynamic_pointer_cast<Item>(newObject)));
            break;

        default:
            std::cerr << "Reached default. Incorrect input " + std::to_string(type) + "type in spawnRandObject class" << endl;
            break;
    }

    // Add newObject to gameMap:
    gameMap.addTile(x, y, std::move(newObject));
}

// Create the player based on the chosen race
bool GameModel::createPlayerAtRandPosn() {
    pair<int, int> pos = randomSpawnablePosition().second;
    spawnObject(pos.first, pos.second, '@');
    return true;
}

void GameModel::createStairAtRandPosn() {
    if (isStairCreated) return; // Stair already exists 

    pair<int, int> pos = randomSpawnablePosition().second;
    spawnObject(pos.first, pos.second, '\\');
}

void GameModel::createEnemyAtRandPosn() {
    const int MAX_ENEMIES = 20;
    int enemyCount = enemies.size();
    pair<int, int> pos = make_pair(0, 0);

    while (enemyCount < MAX_ENEMIES) {
        pair<int, int> pos = randomSpawnablePosition().second;
        spawnRandObject(pos.first, pos.second, 'E');
        ++enemyCount;
    }
}

void GameModel::createGoldAtRandPosn() {
    const int MAX_GOLD_PILES = 10;
    int goldPileCount= 0;
    int itemId = NOTHING;

    // Determine how many Gold items already exist:
    for (auto item: items) {
        itemId = item->getTileID();
        if (itemId == SMALLGOLD || itemId == NORMALGOLD || itemId == MERCHANTHOARD || itemId == DRAGONHOARD) {
            goldPileCount++;
        }
    }

    pair<int, int> pos = make_pair(0, 0);
    
    // Spawn remaining Gold to make 10
    while (goldPileCount < MAX_GOLD_PILES) {
        pair<int, int> pos = randomSpawnablePosition().second;
        spawnRandObject(pos.first, pos.second, 'G');
        ++goldPileCount;
    }
}

void GameModel::createPotionAtRandPosn() {
    const int MAX_POTIONS = 10;
    int potionCount= 0;
    int itemId = NOTHING;

    // Determine how many Potion items already exist:
    for (auto item: items) {
        itemId = item->getTileID();
        if (!(itemId == SMALLGOLD || itemId == NORMALGOLD || itemId == MERCHANTHOARD || itemId == DRAGONHOARD)) {
            potionCount++;
        }
    }

    pair<int, int> pos = make_pair(0, 0);
    
    // Spawn remaining Potion to make 10
    while (potionCount < MAX_POTIONS) {
        pair<int, int> pos = randomSpawnablePosition().second;
        spawnRandObject(pos.first, pos.second, 'P');
        ++potionCount;
    }
}

void GameModel::createDragonAndHoardAtRandPosn() {
    if (isDragonHoardCreated && isDragonCreated) return; // both already exist
    if (isDragonHoardCreated) { // only DragonHoard exists
        if (!(dragonPosn.first >=0 && dragonPosn.second >= 0)) { // dragonHoard exists but dragon does not
            dragonPosn = findAvailableTileAround(dragonHoardPosn.first, dragonHoardPosn.second);
        }
        isDragonCreated = true;
        dragon = std::make_shared<Dragon>(dragonPosn.first, dragonPosn.second, dragonHoard);
        enemies.emplace_back(dragon);
        gameMap.addTile(dragonPosn.first, dragonPosn.second, dragon);
    } else { // neither Dragon nor Dragonhoard exist
        dragonPosn = randomSpawnablePosition().second;
        dragonHoardPosn = findAvailableTileAround(dragonPosn.first, dragonPosn.second);
        isDragonCreated = true;
        isDragonHoardCreated = true;
        dragonHoard = std::make_shared<DragonHoard>(dragonHoardPosn.first, dragonHoardPosn.second, true);
        dragon = std::make_shared<Dragon>(dragonPosn.first, dragonPosn.second, dragonHoard);
        enemies.emplace_back(dragon);
        items.emplace_back(dragonHoard);
        gameMap.addTile(dragonPosn.first, dragonPosn.second, dragon);
        gameMap.addTile(dragonHoardPosn.first, dragonHoardPosn.second, dragonHoard);
    }

}

pair<int, pair<int, int>> GameModel::randomSpawnablePosition() {
    map<int, vector<pair<int, int>>>& room_floortile_mapping = gameMap.getRoomMapping();
    int num_rooms = gameMap.getNumRooms();

    int rand_room = rand() % num_rooms;

    for (int i = 0; i < num_rooms; i++) {
        rand_room = (rand_room + i) % num_rooms;
        vector<pair<int, int>> floortiles_in_room = room_floortile_mapping[rand_room];
        int room_size = floortiles_in_room.size();
        int rand_tile = rand() % room_size;
        for (int i = 0; i < room_size; i++) {
            rand_tile = (rand_tile + i) % room_size;
            if (gameMap.tileIDAt(floortiles_in_room[rand_tile].first, floortiles_in_room[rand_tile].second) == FLOORTILE) {
                return make_pair(rand_room, floortiles_in_room[rand_tile]);
            }
        }
    }

    return make_pair(-1, make_pair(-1, -1));
}

bool GameModel::canMoveHere(int x, int y) {
    int id = gameMap.tileIDAt(x, y);
    if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR || id == NORMALGOLD || id == SMALLGOLD || id == MERCHANTHOARD || id == DRAGONHOARD || id == STAIR) {
        return true;
    }
    return false;
}

// {N = 0, NE, E, SE, S, SW, W, NW}
// Move the player in the specified direction on the gameMap and updates Player's internal position
bool GameModel::movePlayer(Directions direction) {
    pair<int, int> posNow = player->getPosn();
    pair<int, int> moveDirection = DIRECTIONS_POSN_CHANGE.at(direction);
    pair<int, int> newPosn = make_pair<int, int>(posNow.first + moveDirection.first, posNow.second + moveDirection.second);
    const int id = gameMap.tileIDAt(newPosn.first, newPosn.second);
    Tile * tileAtNewPosn = gameMap.tileAt(newPosn.first, newPosn.second);
    
    if (canMoveHere(newPosn.first, newPosn.second)) {
        // Add gold pick-up functionality
        if (id == NORMALGOLD || id == SMALLGOLD || id == MERCHANTHOARD || (id == DRAGONHOARD && dynamic_cast<DragonHoard *> (tileAtNewPosn)->canPlayerPickup(player.get()))) {
            player->setGoldCount(player->getGoldCount() + dynamic_cast<Gold *>(tileAtNewPosn)->getValue());
            gameMap.removeTile(newPosn.first, newPosn.second);
        } else if (id == STAIR) {
            nextFloor();
            return false;
        }

        // Move the player to the new square:
        player->setPosition(newPosn.first, newPosn.second);
        gameMap.moveTile(posNow.first, posNow.second, moveDirection.first, moveDirection.second, gameMap.tileAt(posNow.first, posNow.second));
    }
    return true;
}


bool GameModel::isValidAttack(int x, int y) {
    int tileType = gameMap.typeTypeAt(x, y);
    if (tileType == ENEMY) {
        return true;
    }
    return false;
}

bool GameModel::playerAttack(Directions direction) {
    pair<int, int> posNow = player->getPosn();
    pair<int, int> attackDirection = DIRECTIONS_POSN_CHANGE.at(direction);
    pair<int, int> enemyPosn = make_pair<int, int>(posNow.first + attackDirection.first, posNow.second + attackDirection.second);

    if (isValidAttack(enemyPosn.first, enemyPosn.second)) {
        Enemy * enemyToAttack = dynamic_cast<Enemy *>(gameMap.tileAt(enemyPosn.first, enemyPosn.second));
        int enemyID = gameMap.tileIDAt(enemyPosn.first, enemyPosn.second);
        player->attackEnemy(enemyToAttack);

        // handle enemy death 
        if (enemyToAttack->getHP() <= 0) {
            // Remove the enemy:
            gameMap.removeTile(enemyPosn.first, enemyPosn.second);
            
            // Add gold to player
            if (enemyID != HUMAN) {
                player->setGoldCount(player->getGoldCount() + (rand() % 2) + 1);
            } else {
                spawnObject(enemyPosn.first, enemyPosn.second, '6'); // 6 - NormalGold
                std::pair<int, int> spawnSecondGoldPosn = findAvailableTileAround(enemyPosn.first, enemyPosn.second);
                spawnObject(spawnSecondGoldPosn.first, spawnSecondGoldPosn.second, '6');
            }
            
        }
    }
    return true;
}

bool GameModel::enemyAction() {
    for (auto enemy: enemies) {
        (enemy.get())->takeAction(player.get(), gameMap);
    }
    return true;
}


// Use a potion
bool GameModel::usePotion(Directions direction) {
    pair<int, int> directionVec = DIRECTIONS_POSN_CHANGE.at(direction);
    pair<int, int> posNow = player->getPosn();
    pair<int, int> potionPosn = make_pair(posNow.first + directionVec.first, posNow.second + directionVec.second);

    int id = gameMap.tileIDAt(potionPosn.first, potionPosn.second);
    player->usePotion(id);
    gameMap.removeTile(potionPosn.first, potionPosn.second);
    return true;
}

GameMap &GameModel::getMap() {
    return gameMap; 
}

// Go to the next floor
void GameModel::nextFloor() {
    if (floorLevel < 5) {
        floorLevel += 1;
        isStairCreated = false;
        resetFloor();
        status_message = "You've moved up a floor!";
        notifyobserver();
        status_message = "";
    } else {
        endGame(true);
    }
}

// Set the score
double GameModel::calculateScore() {
    int id = player->getTileID();
    if (player->triggerAbility(SHADE, 0)) {
        return 1.5 * player->getGoldCount();
    }
    return player->getGoldCount();
}

// Update the game state
void GameModel::updateGame() {
    player->triggerAbility(TROLL, 0);

    if (player->getHP() <= 0) {
        endGame(false);
        return;
    }

    enemyAction();

    notifyobserver();
    status_message = "";
}

bool GameModel::startGame() {
    status_message = "Game Start! Input your commands: ";
    notifyobserver();
    status_message = "";
}

// Reset the floor
bool GameModel::resetFloor() {
    GameMap new_map;
    gameMap = new_map;
    enemies = std::vector<std::shared_ptr<Enemy>>{};
    items = std::vector<std::shared_ptr<Item>> {};
    cells = std::vector<std::shared_ptr<Cell>> {};
    ifstream mapFileStream{mapFile};
    initializeMap(mapFileStream, isMapProvided);
}

bool GameModel::endGame(bool win) {
    string smsg;
    if (win) {
        smsg = "Congratuations! You Win!!! Your score is: " + to_string(calculateScore()) + "\n";
    } else {
        smsg = "Oops! You Lose :(\n";
    }

    smsg += "Please press r to restart the game, q to quit, or if you'd like, keep exploring!\n";

    status_message = smsg;
    notifyobserver();
    status_message = "";
}

bool GameModel::freezeEnemy() {
    for (auto it : enemies) {
        (it.get())->setFrozen(true);
    }
    enemyFrozen = true;
}

bool GameModel::unfreezeEnemy() {
    for (auto it : enemies) {
        (it.get())->setFrozen(false);
    }
    enemyFrozen = false;
}

bool GameModel::isEnemyFrozen() {
    return enemyFrozen;
}

void GameModel::getStatusMessage(string msg) {
    status_message = msg;
}

string GameModel::getStatusMessage() {
    return status_message;
}

// Destructor
GameModel::~GameModel() {}

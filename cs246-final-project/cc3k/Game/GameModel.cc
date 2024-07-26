#include "GameModel.h"
using namespace std;

// Get the ID of the tile at the given coordinates
int GameModel::tileIDAt(int x, int y) {
    return gameMap.tileIDAt(x, y);
}

// Initialize the map
void GameModel::initializeMap(ifstream &mapFile, bool isMapProvided) {
    // Initialize the map from a file:
    ifstream empty_map_file{"MapFiles/emptyfloor.txt"};
    if (!isMapProvided) {
        readMap(empty_map_file);
    } else {
        readMap(mapFile);
    }

    // Initialize the remaining objects which have not yet been created:
    createPlayerAtRandPosn();
    createStairAtRandPosn();
    createPotionAtRandPosn();
    createGoldAtRandPosn();
    createEnemyAtRandPosn();
    createDragonAndHoardAtRandPosn();

}

// Read the map from the file: either provided one or emptyfloor.txt
void GameModel::readMap(std::ifstream &mapFile) {
    string line;
    int y = 0; // Line number

    while (getline(mapFile, line)) {
        for (int x = 0; x < line.size(); ++x) {
            char type = line[x];
            // Process each character - spawn new object and add it to the gameMap
            spawnObject(x, y, type);
        } //for
        y++; // Move to the next line
    } //while
}

// Spawn a specific type of game object and add it to the gameMap
void GameModel::spawnObject(int x, int y, char type) {
    CellCreator makeCell;
    EnemyCreator makeEnemy;
    ItemCreator makeItem;
    PlayerCreator makePlayer;
    std::unique_ptr<Tile> newObject;
    int id = NOTHING;

    if (type == '@') { // Input char is player
        newObject = makePlayer.spawnPlayer(x, y, playerRace, effectHandler.get());
        player = std::move(newObject); // initialize the player
        isPlayerCreated = true;

    } else if (cellMap.count(type)) { // Input char is a cell
        id = cellMap.at(type);

        if (id == STAIR) isStairCreated = true;

        newObject = makeCell.spawnTile(x, y, id, false);
        cells.emplace_back(std::move(newObject)); // add to cell vector

    } else if (itemMap.count(type)) { // Input char is an Item
        id = itemMap.at(type);
        newObject = makeItem.spawnTile(x, y, id, false);
        items.emplace_back(std::move(newObject));

    } else if (enemyMap.count(type)) { // Input char is an Enemy
        id = enemyMap.at(type);
        newObject = makeEnemy.spawnTile(x, y, id, false);
        enemies.emplace_back(std::move(newObject)); // add to enemies vector

    } else {
        std::cerr << "Reached default. Invalid input " + to_string(type) + "type in spawnObject class" << endl;
        return;
    }

    // Add newObject to gameMap:
    gameMap.addTile(x, y, std::move(newObject));
}

// Spawn a random game object(Item or Enemy) and add it to the gameMap
void GameModel::spawnRandObject(int x, int y, char type) {
    CellCreator makeCell;
    EnemyCreator makeEnemy;
    ItemCreator makeItem;
    std::unique_ptr<Tile> newObject;

    switch (type) {
        case 'E':
            newObject = makeEnemy.spawnTile(x, y, HUMAN, true); // default value for id
            enemies.emplace_back(std::move(newObject));
            break;

        case 'G':
            newObject = makeItem.spawnTile(x, y, NORMALGOLD, true); // default value for id
            items.emplace_back(std::move(newObject));
            break;

        case 'P':
            newObject = makeItem.spawnTile(x, y, RESTOREHEALTH, true); // default value for id
            items.emplace_back(std::move(newObject));
            break;

        default:
            std::cerr << "Reached default. Invalid input " + to_string(type) + "type in spawnRandObject class" << endl;
            return;
    }

    // Add newObject to gameMap:
    gameMap.addTile(x, y, std::move(newObject));
}

// Create the player based on the chosen race
bool GameModel::createPlayerAtRandPosn() {
    if (isPlayerCreated) return false; // Player already exists

    pair<int, int> pos = randomPosition();
    spawnObject(pos.first, pos.second, '@');
    return true;
}

void GameModel::createStairAtRandPosn() {
    if (isStairCreated) return; // Stair already exists 

    pair<int, int> pos = randomPosition();
    spawnObject(pos.first, pos.second, '\\');
}

void GameModel::createEnemyAtRandPosn() {
    const int MAX_ENEMIES = 20;
    int enemyCount = enemies.size();
    pair<int, int> pos = make_pair(0, 0);

    while (enemyCount < MAX_ENEMIES) {
        pair = randomPosition();
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
        pair = randomPosition();
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
        pair = randomPosition();
        spawnRandObject(pos.first, pos.second, 'P');
        ++potionCount;
    }
}

void GameModel::createDragonAndHoardAtRandPosn() {
    if (isDragonHoardCreated && isDragonCreated) return; // both already exist
    
}

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

// Move the player in the specified direction
bool GameModel::movePlayer(string direction) {
    PlayerCommand dir = processCommand(direction);
    
    
}

// Move the enemy in a random direction
bool GameModel::moveEnemyInRandomDirection() {

}

// Attack the player
bool GameModel::enemyAttack(shared_ptr<GameObject> enemyThatAttacks) {

}

// Player attack
bool GameModel::playerAttack(string direction, shared_ptr<GameObject> enemyToAttack) {

}


// Use a potion
bool GameModel::usePotion(string) {

}

// Start the game
bool GameModel::startGame() {

}

// Go to the next floor
void GameModel::nextFloor(ifstream &mapFile, bool isMapProvided) {

}

// Restart the game
bool GameModel::restartGame() {

}

// Quit the game
void GameModel::quitGame() {

}

// Set the score
bool GameModel::setScore() {

}

// End the game
bool GameModel::endGame() {

}

// Update the game state
void GameModel::updateGame() {

}

// Reset the floor
bool GameModel::resetFloor(Tile* tile) {

}

// Destructor
GameModel::~GameModel() {

}

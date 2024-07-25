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
    createStairAtRandPosition();
    createPotionAtRandPosn();
    createGoldAtRandPosn();
    createEnemyAtRandPosn();
    createDragonAndHoardAtRandPosn();

}

// Read the map from the file: either provided one or emptyfloor.txt
void GameModel::readMap(std::istream &mapFile) {
    string line;
    int y = 0; // Line number

    while (getline(mapFile, line)) {
        for (int x = 0; x < line.size(); ++x) {
            char type = line[x];
            // Process each character - spawn new object and add it to the gameMap
            spawnObject(int x, int y, char type);
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
        newObject = makePlayer.spawnPlayer(x, y, playerRace, ehr);
        player = std::move(newObject); // initialize the player
        playerCreated = true;

    } else if (cellMap.count(type)) { // Input char is a cell
        id = cellMap[type];

        if (id == STAIR) isStairCreated = true;

        newObject = makeCell.spawnTile(x, y, id, false);
        cells.emplace_back(std::move(newObject)); // add to cell vector

    } else if (itemMap.count(type)) { // Input char is an Item
        id = itemMap[type];
        newObject = makeItem.spawnTile(x, y, id, false);
        items.emplace_back(std::move(newObject));

    } else if (enemyMap.count(type)) { // Input char is an Enemy
        id = enemyMap[type];
        newObject = makeEnemy.spawnTile(x, y, id, false);
        enemies.emplace_back(std::move(newObject)); // add to enemies vector

    } else {
        std::cerr << "Reached default. Invalid input " + type + "type in spawnObject class" << endl;
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
            std::cerr << "Reached default. Invalid input " + type + "type in spawnRandObject class" << endl;
            return;
    }

    // Add newObject to gameMap:
    gameMap.addTile(x, y, std::move(newObject));
}

// Create the player based on the chosen race
bool GameModel::createPlayerAtRandPosn() {
    if (isPlayerCreated) return false; // Player already exists

    pair<int, int> pos = randomPosition();
    spawnObject(pos.x, pos.y, '@');
    return true;
}

void GameModel::createStairAtRandPosn() {
    if (isStairCreated) return; // Stair already exists 

    pair<int, int> pos = randomPosition();
    spawnObject(pos.x, pos.y, '\\');
}

void GameModel::createEnemyAtRandPosn() {
    const int MAX_ENEMIES = 20;
    int enemyCount = enemies.size();
    pair<int, int> pos = make_pair(0, 0);

    while (enemyCount < MAX_ENEMIES) {
        pair = randomPosition();
        spawnRandObject(pos.x, pos.y, 'E');
        ++enemyCount;
    }
}

void GameModel::createGoldAtRandPosn() {
    const int MAX_GOLD_PILES = 10;
    int goldPileCount= 0;
    int itemId = NOTHING;

    // Determine how many Gold items already exist:
    for (auto item: items) {
        itemId = item.getTileID();
        if (itemID == SMALLGOLD || itemID == NORMALGOLD || itemID == MERCHANTHOARD || itemID == DRAGONHOARD) {
            goldPileCount++;
        }
    }

    pair<int, int> pos = make_pair(0, 0);
    
    // Spawn remaining Gold to make 10
    while (goldPileCount < MAX_GOLD_PILES) {
        pair = randomPosition();
        spawnRandObject(pos.x, pos.y, 'G');
        ++goldPileCount;
    }
}

void GameModel::createPotionAtRandPosn() {
    const int MAX_POTIONS = 10;
    int potionCount= 0;
    int itemId = NOTHING;

    // Determine how many Potion items already exist:
    for (auto item: items) {
        itemId = item.getTileID();
        if (!(itemID == SMALLGOLD || itemID == NORMALGOLD || itemID == MERCHANTHOARD || itemID == DRAGONHOARD)) {
            potionCount++;
        }
    }

    pair<int, int> pos = make_pair(0, 0);
    
    // Spawn remaining Potion to make 10
    while (potionCount < MAX_POTIONS) {
        pair = randomPosition();
        spawnRandObject(pos.x, pos.y, 'P');
        ++potionCount;
    }
}

void GameModel::createDragonAndHoardAtRandPosn() {
    if (isDragonHoardCreated && isDragonCreated) return; // both already exist
    
}

// Move the player in the specified direction
bool GameModel::movePlayer(string direction) {

}

// Move the enemy in a random direction
bool GameModel::moveEnemyInRandomDirection() {

}

// Check if the move is valid
bool GameModel::isValidMove(shared_ptr<GameObject> gameObject) {

}

// Attack the player
bool GameModel::enemyAttack(shared_ptr<GameObject> enemyThatAttacks) {

}

// Player attack
bool GameModel::playerAttack(string direction, shared_ptr<GameObject> enemyToAttack) {

}

// Check if the attack is valid
bool GameModel::isValidAttack(shared_ptr<GameObject> enemy) {

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

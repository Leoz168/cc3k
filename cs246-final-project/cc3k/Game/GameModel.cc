#include "GameModel.h"
#include "mapfileTileMap.h"
using namespace std;

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
        readMap(mapFile);
        createPlayerAtRandPosn();
        createStairAtRandPosn();
        createPotionAtRandPosn();
        createGoldAtRandPosn();
        createEnemyAtRandPosn();
        createDragonAndHoardAtRandPosn();
    } else {
        readMap(mapFile);
    }
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

        if (!isDragonHoardCreated && id == DRAGONHOARD) { // init dragon hoard separately
            dragonHoardPosn = std::make_pair(x, y);
            dragonHoard = std::make_shared<DragonHoard>(x, y, true);
            isDragonHoardCreated = true;
            items.emplace_back(dragonHoard);
            gameMap.addTile(x, y, dragonHoard);
            return;
        }

        newObject = makeItem.spawnTile(x, y, id, false);
        items.emplace_back(std::move(newObject));

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
        enemies.emplace_back(std::move(newObject)); // add to enemies vector

    } else {
        std::cerr << "Reached default. Invalid input " + std::to_string(type) + "type in spawnObject class" << endl;
        return;
    }

    // Add newObject to gameMap:
    gameMap.addTile(x, y, newObject.get());
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
            std::cerr << "Reached default. Incorrect input " + std::to_string(type) + "type in spawnRandObject class" << endl;
            break;
    }

    // Add newObject to gameMap:
    gameMap.addTile(x, y, std::move(newObject));
}

// Create the player based on the chosen race
bool GameModel::createPlayerAtRandPosn() {
    if (isPlayerCreated) return false; // Player already exists

    pair<int, int> pos = randomSpawnablePosition();
    spawnObject(pos.first, pos.second, '@');
    return true;
}

void GameModel::createStairAtRandPosn() {
    if (isStairCreated) return; // Stair already exists 

    pair<int, int> pos = randomSpawnablePosition();
    spawnObject(pos.first, pos.second, '\\');
}

void GameModel::createEnemyAtRandPosn() {
    const int MAX_ENEMIES = 20;
    int enemyCount = enemies.size();
    pair<int, int> pos = make_pair(0, 0);

    while (enemyCount < MAX_ENEMIES) {
        pair = randomSpawnablePosition();
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
        pair = randomSpawnablePosition();
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
        pair = randomSpawnablePosition();
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
        dragonPosn = randomSpawnablePosition();
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
    if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR || id == NORMALGOLD || id == SMALLGOLD || id == MERCHANTHOARD) {
        return true;
    }
    return false;
}

// {N = 0, NE, E, SE, S, SW, W, NW}
// Move the player in the specified direction on the gameMap and updates Player's internal position
bool GameModel::movePlayer(Directions direction) {
    pair<int, int> posNow = player->getPosn();
    pair<int, int> moveDirection = directionMap.at(direction);
    pair<int, int> newPosn = make_pair<int, int>(posNow.first + moveDirection.first, posNow.second + moveDirection.second);
    const int id = gameMap.tileIDAt(newPosn.first, newPosn.second);
    Tile * tileAtNewPosn = gameMap.tileAt(newPosn.first, newPosn.second);
    
    if (canMoveHere(newPosn.first, newPosn.second)) {
        // Add gold pick-up functionality
        if (id == NORMALGOLD || id == SMALLGOLD || id == MERCHANTHOARD || (id == DRAGONHOARD && dynamic_cast<DragonHoard *> (tileAtNewPosn)->canPlayerPickUp(player))) {
            player->setGoldCount(player->getGoldCount() + dynamic_cast<Gold *>(tileAtNewPosn)->getValue());
            gameMap.removeTile(newPosn.first, newPosn.second);
        }

        // Move the player to the new square:
        player->setPosition(newPosn.first, newPosn.second);
        gameMap.moveTile(posNow.first, posNow.second, moveDirection.first, moveDirection.second, gameMap.tileAt(posNow.first, posNow.second));
    }

}

bool GameModel::playerAttack(Directions direction) {
    pair<int, int> posNow = player->getPosn();
    pair<int, int> attackDirection = directionMap.at(direction);
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
                player->setGoldCount(setGoldCount() + 1);
            } else {
                spawnObject(enemyPosn.first, enemyPosn.second, '6'); // 6 - NormalGold
                std::pair<int, int> spawnSecondGoldPosn = findAvailableTileAround(enemyPosn.first, enemyPosn.second);
                spawnObject(spawnSecondGoldPosn.first, spawnSecondGoldPosn.second, '6');
            }
            
        }
    }
}

bool GameModel::isValidAttack(int x, int y) {
    int tileType = gameMap.typeTypeAt(x, y);
    if (tileType == ENEMY) {
        return true;
    }
    return false;
}

bool usePotion(Directions direction);

// Start the game
bool GameModel::startGame() {

}

// Go to the next floor
void GameModel::nextFloor(ifstream &mapFile, bool isMapProvided) {

}

// Restart the game
bool GameModel::restartGame() {

}

// Set the score
int calculateScore() {

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

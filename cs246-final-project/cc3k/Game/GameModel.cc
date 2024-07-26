#include "GameModel.h"
#include "MapFiles/mapfileTileMap.h"
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
    if (isDragonHoardCreated) { // only DragonHoard exists
        if (!(dragonPosn.first >=0 && dragonPosn.second >= 0)) { // dragonHoard exists but dragon does not
            dragonPosn = findAvailableTileAround(dragonHoardPosn.first, dragonHoardPosn.second);
        }
        isDragonCreated = true;
        dragon = std::make_shared<Dragon>(dragonPosn.first, dragonPosn.second, dragonHoard);
        enemies.emplace_back(dragon);
        gameMap.addTile(dragonPosn.first, dragonPosn.second, dragon);
    } else { // neither Dragon nor Dragonhoard exist
        dragonPosn = randomPosition();
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


// N = 0, NE, E, SE, S, SW, W, NW;
// isAvailableTileForSpawn(int x, int y)

// Move the player in the specified direction
bool GameModel::movePlayer(Directions direction) {
    pair posNow = player->getPosn();
    switch (direction)
    {
    case Directions::N:
        int id = gameMap.tileIDAt(posNow.first, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE) {
            gameMap.moveTile(posNow.first, posNow.second, 0, -1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::NE:
        int id = gameMap.tileIDAt(posNow.first + 1, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE) {
            gameMap.moveTile(posNow.first, posNow.second, 1, -1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::N:
        int id = gameMap.tileIDAt(posNow.first, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE) {
            gameMap.moveTile(posNow.first, posNow.second, 0, -1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::N:
        int id = gameMap.tileIDAt(posNow.first, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE) {
            gameMap.moveTile(posNow.first, posNow.second, 0, -1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::N:
        int id = gameMap.tileIDAt(posNow.first, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE) {
            gameMap.moveTile(posNow.first, posNow.second, 0, -1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;
    
    default:
        break;
    }
}


// Use a potion
bool usePotion(Directions direction) {

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

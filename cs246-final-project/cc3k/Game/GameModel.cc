#include "GameModel.h"
#include "mapfileTileMap.h"
#include <regex>
#include <algorithm>
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

bool GameModel::canMoveHere(int x, int y) {
    int id = gameMap.tileIDAt(x, y);
    if (id == FLOORTILE || id == DOORWAY || id == PASSAGE) {
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

// Read the map from the file: either provided one or emptyfloor.txt
void GameModel::readMap(std::ifstream &mapFile, bool isMapProvided) {
    string line;
    int y = 0; // Line number
    map<int, string> reverseCellMap;

    for (auto it : cellMap) {
        reverseCellMap[it.second] = reverseCellMap[it.first];
    }

    const regex horizontal_border{"\\" + reverseCellMap[VWALL] + reverseCellMap[HWALL] + "*\\" + reverseCellMap[VWALL]};

    if (isMapProvided) {
        for (int i = 1; i < floorLevel; i++) {
            int borders = 0;
            while (getline(mapFile, line) && borders < 2) {
                if (regex_match(line, horizontal_border)) borders++;
            }
        }
    }

    std::vector<string> floor_lines;
    std::vector<std::vector<bool>> tiles_processed;

    int borders = 0;
    while (getline(mapFile, line) && borders < 2) {
        int line_size = line.length();
        std::vector<bool> line_processed;
        for (int i = 0; i < line_size; i++) {
            line_processed.emplace_back(false);
        }

        floor_lines.emplace_back(line);

        tiles_processed.emplace_back(move(line_processed));

        if (regex_match(line, horizontal_border)) borders++;
    }

    for (int i = 0; i < floor_lines.size(); ++i) {
        string& line = floor_lines[i];
        for (int j = 0; line.size(); ++j) {
            char type = line[j];
            if (type == reverseCellMap)
        }
    }

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
    std::shared_ptr<Tile> newObject;
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


// {N = 0, NE, E, SE, S, SW, W, NW}
// Move the player in the specified direction
bool GameModel::movePlayer(Directions direction) {
    pair posNow = player->getPosn();
    switch (direction)
    {
    case Directions::N:
        int id = gameMap.tileIDAt(posNow.first, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR) {
            gameMap.moveTile(posNow.first, posNow.second, 0, -1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::NE:
        int id = gameMap.tileIDAt(posNow.first + 1, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR) {
            gameMap.moveTile(posNow.first, posNow.second, 1, -1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::E:
        int id = gameMap.tileIDAt(posNow.first + 1, posNow.second);
        if (id == FLOORTILE || id == PASSAGE) {
            gameMap.moveTile(posNow.first, posNow.second, 1, 0, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::SE:
        int id = gameMap.tileIDAt(posNow.first + 1, posNow.second + 1);
        if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR) {
            gameMap.moveTile(posNow.first, posNow.second, 1, 1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::S:
        int id = gameMap.tileIDAt(posNow.first, posNow.second + 1);
        if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR) {
            gameMap.moveTile(posNow.first, posNow.second, 0, 1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::SW:
        int id = gameMap.tileIDAt(posNow.first + 1, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR) {
            gameMap.moveTile(posNow.first, posNow.second, 0, 1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::W:
        int id = gameMap.tileIDAt(posNow.first - 1, posNow.second);
        if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR) {
            gameMap.moveTile(posNow.first, posNow.second, -1, 0, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;

    case Directions::NW:
        int id = gameMap.tileIDAt(posNow.first - 1, posNow.second - 1);
        if (id == FLOORTILE || id == PASSAGE || id == DOORWAY || id == STAIR) {
            gameMap.moveTile(posNow.first, posNow.second, -1, -1, gameMap.tileAt(posNow.first, posNow.second));
        }
        break;
    
    default:
        break;
    }
}


// Use a potion
bool usePotion(Directions direction) {

}
bool isValidAttack(int x, int y);
bool usePotion(Directions direction);


// Go to the next floor
void GameModel::nextFloor(ifstream &mapFile, bool isMapProvided) {

}

// Set the score
double GameModel::calculateScore() {
    int id = player->getTileID();
    if (id == TileID::SHADE) {
        return 1.5 * player->getGoldCount();
    }
    return player->getGoldCount();
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

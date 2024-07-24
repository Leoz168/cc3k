#include "GameModel.h"
using namespace std;

// Get the ID of the tile at the given coordinates
int GameModel::tileIDAt(int x, int y) {
    return map.tileIDAt(x, y);
}

// Create the player based on the chosen race
void GameModel::createPlayer(char type) {
    ObjectCreator playerCreator;
    pair<int, int> pos = randomPosition();
    playerRace = playerRaceMap[type];
    player = playerCreator.createObject(pos.first, pos.second, '@', playerRace, false, effectHandler);
}

// Initialize the cells
void GameModel::initializeCells() {

}

// Initialize the map
void GameModel::initializeMap(ifstream &mapFile, bool isMapProvided) {
    if (isMapProvided) {
        readMap(mapFile);
    } else {

    }
}

// Read the map from the file
void GameModel::readMap(istream &mapFile) {

}

// Spawn a random game object
shared_ptr<Tile> GameModel::spawnRandGameObj() {

}

// Spawn a specific type of game object
shared_ptr<Tile> GameModel::spawn(string type) {

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

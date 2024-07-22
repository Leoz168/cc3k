#include <memory>
#include "floor.h"
#include "../GameObject/Player/player.h"

using namespace std;

FloorDecorator::FloorDecorator(Floor*& map, Player* player, std::shared_ptr<Floor> component) :
    map{map},
    player{player},
    component{component}
{}

FloorDecorator::~FloorDecorator() {}

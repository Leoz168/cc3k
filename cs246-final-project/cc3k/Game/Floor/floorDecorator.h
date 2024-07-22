#ifndef FLOORDECORATOR_H
#define FLOORDECORATOR_H

#include <memory>
#include "floor.h"
#include "../Player/player.h"
using namespace std;

class FloorDecorator : public Floor {
        Floor*& map;
        Player* player;
        std::shared_ptr<Floor> component;
    public:
        FloorDecorator(Floor*&, Player*, std::shared_ptr<Floor>);
        virtual int getTileID(int x, int y) = 0;
        virtual Floor* getTilePtr(int x, int y) = 0;
        virtual bool move(int x, int y, int dx, int dy) = 0;
        virtual std::pair<bool, bool> playerAttack(int x, int y) = 0;
        virtual bool playerUsed(int x, int y) = 0;
        virtual bool takeAction(int x, int y) = 0;
        virtual ~FloorDecorator();
};

#endif

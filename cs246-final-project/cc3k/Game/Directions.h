#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include <map>
#include <utility>
#include <string>

const int NUM_DIRECTIONS = 8;
enum Directions {N = 0, NE, E, SE, S, SW, W, NW};
const std::map<Directions, pair<int, int>> DIRECTIONS_POSN_CHANGE {
    {N, make_pair(0, -1)},
    {NE, make_pair(1, -1)},
    {E, make_pair(1, 0)},
    {SE, make_pair(1, 1)},
    {S, make_pair(0, 1)},
    {SW, make_pair(-1, 1)},
    {W, make_pair(-1, 0)},
    {NW, make_pair(-1, -1)}
};

const std::map<Directions, std::string> DIRECTIONS_NAMES {
    {N, "North"},
    {NE, "Northeast"},
    {E, "East"},
    {SE, "Southeast"},
    {S, "South"},
    {SW, "Southwest"},
    {W, "West"},
    {NW, "Northwest"}
};

#endif

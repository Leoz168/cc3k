#ifndef PASSAGE_H
#define PASSAGE_H

#include "Cell.h"

class Passage : public Cell {
    public:
        Passage(int x, int y);
        Tile* getTilePtr();
        ~Passage();
};

#endif

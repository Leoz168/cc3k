#include "TextDisplay.h"
#include "tileCharMapping.h"

void TextDisplay::notify() {
    int cols = gm->getCols();
    int i = 0;
    for (auto it: gm->getMap().getRoomMapping()) {
        std::cout << IDToChar(it.second)
    }
}
#include "TextDisplay.h"
#include "tileCharMapping.h"

void TextDisplay::notify() {
    int row = gm->getMap().getMapRows();
    int col = gm->getMap().getMapCols();
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            std::cout << IDToChar(gm->tileIDAt(i, j));
        }
        std::cout << std::endl;
    }
}

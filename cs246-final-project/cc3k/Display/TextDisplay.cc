#include "TextDisplay.h"
#include "tileCharMapping.h"

TextDisplay::TextDisplay(GameModel* gameSubject) : gm{gameSubject} {
    gm->attach(this);
}

void TextDisplay::notify() {
    int row = gm->getRows();
    int col = gm->getCols();
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            std::cout << IDToChar(gm->tileIDAt(i, j));
        }
        std::cout << std::endl;
    }
}

TextDisplay::~TextDisplay() {
    gm->detach(this);
}

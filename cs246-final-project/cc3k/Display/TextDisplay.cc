#include "TextDisplay.h"
#include "tileCharMapping.h"

TextDisplay::TextDisplay(GameModel* gameSubject) : gm{gameSubject} {
    gm->attach(this);
}

void TextDisplay::notify() {
    int row = gm->getRows();
    int col = gm->getCols();
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            std::cout << IDToChar(gm->tileIDAt(j, i));
        }
        std::cout << std::endl;
    }
}

TextDisplay::~TextDisplay() {
    gm->detach(this);
}

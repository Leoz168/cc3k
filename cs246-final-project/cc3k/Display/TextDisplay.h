#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include "observer.h"
#include "../GameModel.h"

class TextDisplay: public Observer {
        GameModel *gm;
    public:
        void notify() override;
};

#endif

#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include "observer.h"
#include "../GameModel.h"

class TextDisplay: public Observer {
        
    public:
        void notify() override;
};

#endif

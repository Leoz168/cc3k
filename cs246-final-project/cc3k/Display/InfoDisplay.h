#ifndef INFODISPLAY_H
#define INFODISPLAY_H

#include <iostream>

#include "observer.h"
#include "../Game/GameModel.h"

class InfoDisplay: public Observer {
        GameModel *gm;
    public:
        void notify() override;

};

#endif

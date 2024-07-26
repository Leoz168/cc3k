#ifndef INFODISPLAY_H
#define INFODISPLAY_H

#include <iostream>

#include "observer.h"
#include "../Game/GameModel.h"

class InfoDisplay: public Observer {
        GameModel *gm;
    public:
        InfoDisplay(GameModel* gameSubject);
        void notify() override;
        ~InfoDisplay();
};

#endif

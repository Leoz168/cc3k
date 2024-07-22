#include <iostream>

#include "observer.h"
#include "../Game/GameModel.h"
#include "../consts.h"

class InfoDisplay: public Observer {
        GameModel *gm;
    public:
        void notify() override;

};

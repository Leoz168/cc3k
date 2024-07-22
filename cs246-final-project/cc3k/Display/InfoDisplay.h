#include <iostream>

#include "observer.h"
#include "../subject/GameModel.h"
#include "../allConsts.h"

class InfoDisplay: public Observer {
        GameModel *gm;
    public:
        void notify() override;

};

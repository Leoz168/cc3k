#include <iostream>
#include "observer.h"
#include "subject/GameModel.h"

class TextDisplay: public Observer {
        
    public:
        void notify() override;
};

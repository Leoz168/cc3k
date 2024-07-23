#include "effectDecorator.h"

class AtkModifier: public EffectDecorator {
        int atk;
    public:
        AtkModifier(Effect *effect, int atk);
        int getAtkModifier();
        void setAtk(int atk);
        ~AtkModifier();
};

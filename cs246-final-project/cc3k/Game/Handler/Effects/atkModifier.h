#include "effectDecorator.h"

class AtkModifier: public EffectDecorator {
        int atk;
    public:
        AtkModifier(Effect *effect, int atk);
        int getAtkModifier() override;
        void setAtk(int atk);
        ~AtkModifier();
};

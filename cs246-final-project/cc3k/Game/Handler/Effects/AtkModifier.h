#include "EffectDecorator.h"

class AtkModifier: public EffectDecorator {
        int atk;
    public:
        AtkModifier(Effect *next, int atk);
        int getAtkModifier() override;
        int getDefModifier() override;
        void setAtk(int atk);
        ~AtkModifier();
};

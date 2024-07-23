#include "effectDecorator.h"

class DefModifier: public EffectDecorator {
        int def;
    public:
        DefModifier(Effect *effect, int def);
        int getDefModifier() override;
        int getAtkModifier() override;
        void setDef(int def);
        ~DefModifier();
};

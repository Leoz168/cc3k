#include "effecthandler.h"

EffectHandler::EffectHandler(Effect *effect) {}
int EffectHandler::getAtkEffect() {
    return effect->getAtkModifier();
}
int EffectHandler::getDefEffect() {
    return effect->getDefModifier();
}
void EffectHandler::addAtkEffect() {
    
}
void addDefEffect();
void removeAllEffects();
~EffectHandler();

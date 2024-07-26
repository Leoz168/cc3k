#include "EffectHandler.h"

EffectHandler::EffectHandler() :
    effect{unique_ptr<Effect>{new NoEffect{}}} {}

int EffectHandler::getAtkEffect() {
    return effect->getAtkModifier();
}

int EffectHandler::getDefEffect() {
    return effect->getDefModifier();
}

void EffectHandler::addAtkEffect(int atk) {
    effect.reset(new AtkModifier{std::move(effect), atk});
}

void EffectHandler::addDefEffect(int def) {
    effect.reset(new DefModifier{std::move(effect), def});
}

void EffectHandler::removeAllEffects() {
    effect.reset(new NoEffect{});
}

EffectHandler::~EffectHandler() {}

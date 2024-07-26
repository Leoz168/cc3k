#include "DefModifier.h"
DefModifier::DefModifier(std::unique_ptr<Effect> next, int def): EffectDecorator{std::move(next)} , def{def} {}
int DefModifier::getDefModifier() { return def + next->getDefModifier(); }
int DefModifier::getAtkModifier() { return next->getAtkModifier(); }
void DefModifier::setDef(int atk) { this->def = def; }
DefModifier::~DefModifier() {}

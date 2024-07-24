#include "AtkModifier.h"
AtkModifier::AtkModifier(Effect *next, int atk): EffectDecorator{next}, atk{atk} {}
int AtkModifier::getAtkModifier() { return atk + next->getAtkModifier(); }
int AtkModifier::getDefModifier() { return next->getDefModifier(); }
void AtkModifier::setAtk(int atk) { this->atk = atk; }
AtkModifier::~AtkModifier() {}

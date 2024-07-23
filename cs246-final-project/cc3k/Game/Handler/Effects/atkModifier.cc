#include "atkModifier.h"
AtkModifier::AtkModifier(Effect *Effect, int atk): EffectDecorator{effect}, atk{atk} {}
int AtkModifier::getAtkModifier() { return atk; }
void AtkModifier::setAtk(int atk) { this->atk = atk; }
AtkModifier::~AtkModifier() {}

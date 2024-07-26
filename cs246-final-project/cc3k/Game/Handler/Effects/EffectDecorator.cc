#include "EffectDecorator.h"
EffectDecorator::EffectDecorator(std::unique_ptr<Effect> next): next{std::move(next)} {}
EffectDecorator::~EffectDecorator() {}
